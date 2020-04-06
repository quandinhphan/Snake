#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_utils.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Snake";
int stepchange=2;
struct Box{
    int x;
    int y;
    int x0;
    int y0;
    int size=20;
    int stepX=2;
    int stepY=0;

    void render(SDL_Renderer* renderer){
        SDL_Rect filled_rect;
        filled_rect.x = x;
        filled_rect.y = y;
        filled_rect.w = size;
        filled_rect.h = size;
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &filled_rect);
    }


    void move(){
        x+=stepX;
        y+=stepY;
    }
     void moveup(){
        stepY=-stepchange;
        stepX=0;
    }
    void movedown(){
        stepY=stepchange;
        stepX=0;
    }
    void moveright(){
        stepY=0;
        stepX=stepchange;
    }
    void moveleft(){
        stepY=0;
        stepX=-stepchange;
    }
    void goback(){
        if(x>SCREEN_WIDTH){
            x=0;
        }
        if(y>SCREEN_HEIGHT){
            y=0;
        }
        if(x<0){
            x=SCREEN_WIDTH;
        }
        if(y<0){
            y=SCREEN_HEIGHT;
        }
    }
    void createRandombox(){
        do{
            x=rand()%SCREEN_WIDTH;
            y=rand()%SCREEN_HEIGHT;
        }while(x%stepchange!=0||y%stepchange!=0);
    }
};

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    SDL_RenderClear(renderer);
    Box box[30];
    box[0].x=10;
    box[0].y=10;
    SDL_Event e;
    Box randbox;
    randbox.x=100;
    randbox.y=100;
    int i;


    while(true ){
        if(randbox.x==box[0].x&&randbox.y==box[0].y){
            stepchange+=2;
            randbox.createRandombox();
        }
        box[0].goback();
        box[0].x0=box[0].x;
        box[0].y0=box[0].y;
        box[0].move();
        for(i=1;i<30;i++){
            box[i].x0=box[i].x;
            box[i].y0=box[i].y;
            box[i].x=box[i-1].x0;
            box[i].y=box[i-1].y0;
        }
        cout << box[0].x << " " << box[0].y << " " << randbox.x << " " << randbox.y << endl;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        randbox.render(renderer);
        for(i=0;i<30;i++){
            box[i].render(renderer);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(100);

        if ( SDL_PollEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) break;

        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break;
        		case SDLK_LEFT: box[0].moveleft(); break;
            	case SDLK_RIGHT: box[0].moveright(); break;
            	case SDLK_DOWN:box[0].movedown(); break;
            	case SDLK_UP:box[0].moveup(); break;
        		default: break;
			}
        }
    }

    quitSDL(window, renderer);
    return 0;
}

