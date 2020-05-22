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

    const string filename0="boxmode.png";
    SDL_Texture* texture0=LoadTexture(filename0);
    SDL_Rect SourceRect0=SourceRect(texture0);
    SDL_Rect desRect0=desRect(290,5,310,295);

    const string filename1="classicmode.png";
    SDL_Texture* texture1=LoadTexture(filename1);
    SDL_Rect SourceRect1=SourceRect(texture1);
    SDL_Rect desRect1=desRect(290,5,310,295);

    const string filename2="menu1.png";
    SDL_Texture* texture2=LoadTexture(filename2);
    SDL_Rect SourceRect2=SourceRect(texture2);
    SDL_Rect desRect2=desRect(0,0,600,600);

    const string filename3="keys.png";
    SDL_Texture* texture3=LoadTexture(filename3);
    SDL_Rect SourceRect3=SourceRect(texture3);
    SDL_Rect desRect3=desRect(0,300,600,300);

    const string filename4="gamemode.png";
    SDL_Texture* texture4=LoadTexture(filename4);
    SDL_Rect SourceRect4=SourceRect(texture4);
    SDL_Rect desRect4=desRect(0,0,600,600);

    while(true){
       MenurunningOrGamemode(renderer, texture2, SourceRect2, desRect2);
        if ( SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) break;
        if (e.type == SDL_MOUSEBUTTONDOWN) {

            int x=e.motion.x;
            int y=e.motion.y;
            SDL_GetMouseState(&x,&y);

            if(e.button.button==SDL_BUTTON_LEFT){

                if(x>200&&x<350&&y>525&&y<595){
                    break;
                }
                else if(x>200&&x<350&&y>450&&y<520){

                    while(true){
                        MenurunningOrGamemode(renderer, texture4, SourceRect4, desRect4);
                        if ( SDL_PollEvent(&e) == 0) continue;
                        if (e.type == SDL_MOUSEBUTTONDOWN) {
                            SDL_GetMouseState(&x,&y);
                            if(e.button.button==SDL_BUTTON_LEFT){

                                if(x>10&&x<300&&y>150&&y<500){
                                    ClassicMode(renderer, texture1, SourceRect1, desRect1, texture3, SourceRect3, desRect3);
                                    break;
                                }
                                else if(x>300&&x<590&&y>150&&y<500){
                                    BoxMode(renderer, texture0, SourceRect0, desRect0, texture3, SourceRect3, desRect3);
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    SDL_DestroyTexture(texture0);
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_DestroyTexture(texture4);
    quitSDL(window, renderer);

    return 0;
}
