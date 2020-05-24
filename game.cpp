#include "game.h"
#include "shape.h"
#include "SDL_utils.h"

void ClassicMode(SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Rect SourceRect1, SDL_Rect desRect1, SDL_Texture* texture3, SDL_Rect SourceRect3, SDL_Rect desRect3){

    SDL_Event e;

    Box box;

    Cycle cycle[841];

    cycle[0].x=20;
    cycle[0].y=20;

    Cycle randcycle;

    randcycle.createFood();

    int snakepoint=1;
    int speedtime=100;
    int dem=0;
    int down=0, up=0, right=0, left=0;

    while(dem==0&&snakepoint!=841){
        eating(cycle[0],randcycle,snakepoint,speedtime);

        cycle[0].goback();
        cycle[0].x0=cycle[0].x;
        cycle[0].y0=cycle[0].y;
        cycle[0].move();

        for(int i=1;i<snakepoint;i++){

            cycle[i].x0=cycle[i].x;
            cycle[i].y0=cycle[i].y;
            cycle[i].x=cycle[i-1].x0;
            cycle[i].y=cycle[i-1].y0;
            if(cycle[i].x==cycle[0].x&&cycle[i].y==cycle[0].y){
                dem++;
            }
        }
        cout << cycle[0].x << " " << cycle[0].y << " " << randcycle.x << " " << randcycle.y << endl;

        SDL_SetRenderDrawColor(renderer, 125, 125, 255, 255);

        SDL_RenderClear(renderer);

        box.render(renderer);

        randcycle.render(renderer);

        for(int i=0;i<snakepoint;i++){
            cycle[i].render(renderer);
        }
        SDL_RenderCopy(renderer, texture1, &SourceRect1, &desRect1);
        SDL_RenderCopy(renderer, texture3, &SourceRect3, &desRect3);

        SDL_RenderPresent(renderer);

        SDL_Delay(speedtime);

        if ( SDL_PollEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) break;

        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE: break;
                case SDLK_LEFT:
                    {
                        if(left==0){
                            cycle[0].moveleft();
                            right=1;
                            up=0;
                            down=0;
                        }
                        break;
                    }
                case SDLK_RIGHT:
                    {
                        if(right==0){
                            cycle[0].moveright();
                            left=1;
                            up=0;
                            down=0;
                        }
                        break;
                    }
                case SDLK_DOWN:
                    {
                        if(down==0){
                            cycle[0].movedown();
                            up=1;
                            right=0;
                            left=0;
                        }
                        break;
                    }
                case SDLK_UP:
                    {
                        if(up==0){
                            cycle[0].moveup();
                            down=1;
                            right=0;
                            left=0;
                        }
                        break;
                    }
                case SDLK_SPACE:waitUntilKeyPressed(); break;
                default: break;
            }
        }
    }
}


void BoxMode(SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Rect SourceRect1, SDL_Rect desRect1, SDL_Texture* texture3, SDL_Rect SourceRect3, SDL_Rect desRect3){

    SDL_Event e;

    Box box;

    Cycle cycle[841];

    cycle[0].x=20;
    cycle[0].y=20;

    Cycle randcycle;

    randcycle.createFood();

    int snakepoint=1;
    int speedtime=100;
    int dem=0;
    int down=0, up=0, right=0, left=0;


    while(dem==0&&snakepoint!=841){
        eating(cycle[0],randcycle,snakepoint,speedtime);

        if(cycle[0].hitthewall()==false){
            break;
        }
        cycle[0].x0=cycle[0].x;
        cycle[0].y0=cycle[0].y;
        cycle[0].move();

        for(int i=1;i<snakepoint;i++){

            cycle[i].x0=cycle[i].x;
            cycle[i].y0=cycle[i].y;
            cycle[i].x=cycle[i-1].x0;
            cycle[i].y=cycle[i-1].y0;
            if(cycle[i].x==cycle[0].x&&cycle[i].y==cycle[0].y){
                dem++;
            }
        }
        cout << cycle[0].x << " " << cycle[0].y << " " << randcycle.x << " " << randcycle.y << endl;

        SDL_SetRenderDrawColor(renderer, 125, 125, 255, 255);

        SDL_RenderClear(renderer);

        box.render(renderer);

        randcycle.render(renderer);

        for(int i=0;i<snakepoint;i++){
            cycle[i].render(renderer);
        }
        SDL_RenderCopy(renderer, texture1, &SourceRect1, &desRect1);
        SDL_RenderCopy(renderer, texture3, &SourceRect3, &desRect3);

        SDL_RenderPresent(renderer);

        SDL_Delay(speedtime);

        if ( SDL_PollEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) break;

        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE: break;
                case SDLK_LEFT:
                    {
                        if(left==0){
                            cycle[0].moveleft();
                            right=1;
                            up=0;
                            down=0;
                        }
                        break;
                    }
                case SDLK_RIGHT:
                    {
                        if(right==0){
                            cycle[0].moveright();
                            left=1;
                            up=0;
                            down=0;
                        }
                        break;
                    }
                case SDLK_DOWN:
                    {
                        if(down==0){
                            cycle[0].movedown();
                            up=1;
                            right=0;
                            left=0;
                        }
                        break;
                    }
                case SDLK_UP:
                    {
                        if(up==0){
                            cycle[0].moveup();
                            down=1;
                            right=0;
                            left=0;
                        }
                        break;
                    }
                case SDLK_SPACE:waitUntilKeyPressed(); break;
                default: break;
            }
        }
    }
}


void MenurunningOrGamemode(SDL_Renderer* renderer, SDL_Texture* texture2, SDL_Rect SourceRect2, SDL_Rect desRect2){
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture2, &SourceRect2, &desRect2);
    SDL_RenderPresent(renderer);
}


