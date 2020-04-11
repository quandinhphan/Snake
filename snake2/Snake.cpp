#include <bits/stdc++.h>
#include <SDL.h>
#include "SDL_utils.h"

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Snake";
const int rad=5;

const int xsquare=5;
const int ysquare=5;
const int wsquare=SCREEN_WIDTH-15;
const int hsquare=(SCREEN_HEIGHT/2)-5;

int stepchange=2*rad;

struct Cycle{
    int x;
    int y;
    int x0;
    int y0;
    int stepX=0;
    int stepY=0;

    Cycle(int _x,int _y){
        x=_x;
        y=_y;
    }
    Cycle(){}

    void render(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        for (int angle = 0; angle < 360; angle++) {
            int xx0, yy0;
            int xx = x + rad * cos(angle);
            int yy = y + rad * sin(angle);
            if(angle>0){
                SDL_RenderDrawLine(renderer, xx, yy, xx0, yy0);
            }
            xx0=xx,yy0=yy;

            SDL_RenderDrawPoint(renderer, xx, yy);
        }
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
        if(x>wsquare-rad){
            x=xsquare+rad;
        }
        else if(x<xsquare+rad){
            x=wsquare-rad;
        }
        if(y>hsquare-rad){
            y=ysquare+rad;
        }
        else if(y<ysquare+rad){
            y=hsquare-rad;
        }
    }
    void createFood(){
        do{
            x=rand()%wsquare+xsquare;
            y=rand()%hsquare+ysquare;
        }while(x%stepchange!=0||y%stepchange!=0);
    }
};

struct Box{

    void render(SDL_Renderer* renderer){
        SDL_Rect filled_rect;
        filled_rect.x = xsquare;
        filled_rect.y = ysquare;
        filled_rect.w = wsquare;
        filled_rect.h = hsquare;
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255)
        SDL_RenderDrawRect(renderer, &filled_rect);
    }
};

void runfaster(int &m){
    if(m>10){
        m=m-5;
    }
    else{
        if(m>1){
            m=m-1;
        }else{
            if(m>0.1){
                m=m-0.1;
            }
            else
                m=m-0.01;
        }
    }
}

int main(int argc, char* argv[])
{
    srand(time(0));
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    SDL_RenderClear(renderer);

    Box box;

    Cycle cycle[30];
    cycle[0].x=20;
    cycle[0].y=20;
    SDL_Event e;
    Cycle randcycle;
    randcycle.x=100;
    randcycle.y=100;
    int i;
    int n=1;
    int m=60;
    int dem=0;


    while(dem==0){
        if(randcycle.x==cycle[0].x&&randcycle.y==cycle[0].y){
            n++;
            runfaster(m);
            randcycle.createFood();
        }
        cycle[0].goback();
        cycle[0].x0=cycle[0].x;
        cycle[0].y0=cycle[0].y;
        cycle[0].move();
        for(i=1;i<n;i++){
            cycle[i].x0=cycle[i].x;
            cycle[i].y0=cycle[i].y;
            cycle[i].x=cycle[i-1].x0;
            cycle[i].y=cycle[i-1].y0;
        }
        cout << cycle[0].x << " " << cycle[0].y << " " << randcycle.x << " " << randcycle.y << endl;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        box.render(renderer);

        randcycle.render(renderer);
        for(i=0;i<n;i++){
            cycle[i].render(renderer);
        }
        SDL_RenderPresent(renderer);
        SDL_Delay(m);

        if ( SDL_PollEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) break;

        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break;
        		case SDLK_LEFT: cycle[0].moveleft(); break;
            	case SDLK_RIGHT: cycle[0].moveright(); break;
            	case SDLK_DOWN:cycle[0].movedown(); break;
            	case SDLK_UP:cycle[0].moveup(); break;
            	case SDLK_SPACE:waitUntilKeyPressed(); break;
        		default: break;
			}
        }
        for(i=2;i<n;i++){
            if(cycle[i].x==cycle[0].x&&cycle[i].y==cycle[0].y){
                dem++;
            }
        }
    }

    quitSDL(window, renderer);
    return 0;
}
