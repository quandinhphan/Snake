#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "shape.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* LoadTexture(string path);
SDL_Surface* surface;
SDL_Texture* texture;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Snake";


SDL_Texture* LoadTexture(string path){
    SDL_Texture* newTexture;
    SDL_Surface* loadedSurface=IMG_Load(path.c_str());
    newTexture=SDL_CreateTextureFromSurface(renderer,loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

SDL_Rect SourceRect(SDL_Texture* texture){
    SDL_Rect SsourceRect;
    SDL_QueryTexture(texture,NULL,NULL, &SsourceRect.w, &SsourceRect.h);

    SsourceRect.x=0;
    SsourceRect.y=0;

    return SsourceRect;
}

SDL_Rect desRect(const int x, const int y, const int w, const int h){
    SDL_Rect dessRect;
    dessRect.x=x;
    dessRect.y=y;
    dessRect.w=w;
    dessRect.h=h;
    return dessRect;
}


int main(int argc, char* argv[])
{
    srand(time(0));

    initSDL(window, renderer, SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);

    SDL_RenderClear(renderer);

    string filename1="snake2.png";
    SDL_Texture* texture1=LoadTexture(filename1);
    SDL_Rect SourceRect1=SourceRect(texture1);
    SDL_Rect desRect1=desRect(0,300,600,300);

    string filename2="menu.png";
    SDL_Texture* texture2=LoadTexture(filename2);
    SDL_Rect SourceRect2=SourceRect(texture2);
    SDL_Rect desRect2=desRect(0,0,600,600);


    while(true){
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
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture2, &SourceRect2, &desRect2);
        SDL_RenderPresent(renderer);
        if ( SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym==SDLK_ESCAPE){
                break;
            }
            if(e.key.keysym.sym!=SDLK_ESCAPE){
                while(dem==0){
                    eating(cycle[0],randcycle,n,m);
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
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);
                    box.render(renderer);

                    randcycle.render(renderer);
                    for(i=0;i<n;i++){
                        cycle[i].render(renderer);
                    }
                    SDL_RenderCopy(renderer, texture1, &SourceRect1, &desRect1);
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
            }
        }
    }

    quitSDL(window, renderer);
    return 0;
}
