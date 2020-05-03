#include <bits/stdc++.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_utils.h"
#include "shape.h"
#include "game.h"

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* LoadTexture(const string path);
SDL_Surface* surface;

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Snake";


SDL_Texture* LoadTexture(const string path){
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

    SDL_Event e;

    const string filename1="E:/snake2.png";
    SDL_Texture* texture1=LoadTexture(filename1);
    SDL_Rect SourceRect1=SourceRect(texture1);
    SDL_Rect desRect1=desRect(0,300,600,300);

    const string filename2="E:/menu.png";
    SDL_Texture* texture2=LoadTexture(filename2);
    SDL_Rect SourceRect2=SourceRect(texture2);
    SDL_Rect desRect2=desRect(0,0,600,600);

    while(true){
        Menurunning(renderer, texture2, SourceRect2, desRect2);
        if ( SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_KEYDOWN) {
            if(e.key.keysym.sym==SDLK_ESCAPE){
                break;
            }
            if(e.key.keysym.sym!=SDLK_ESCAPE){
                Gameplay(renderer, texture1, SourceRect1, desRect1);
            }
        }
    }

    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    quitSDL(window, renderer);

    return 0;
}
