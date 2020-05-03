#include "game.h"
#include "shape.h"
#include "SDL_utils.h"

void Gameplay(SDL_Renderer* renderer, SDL_Texture* texture1, SDL_Rect SourceRect1, SDL_Rect desRect1){

    SDL_Event e;

    Box box;

    Cycle cycle[30];

    cycle[0].x=20;
    cycle[0].y=20;

    Cycle randcycle;

    randcycle.createFood();

    int snakepoint=1;
    int speedtime=100;
    int dem=0;

    while(dem==0){
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
        }
        cout << cycle[0].x << " " << cycle[0].y << " " << randcycle.x << " " << randcycle.y << endl;

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        SDL_RenderClear(renderer);

        box.render(renderer);

        randcycle.render(renderer);

        for(int i=0;i<snakepoint;i++){
            cycle[i].render(renderer);
        }
        SDL_RenderCopy(renderer, texture1, &SourceRect1, &desRect1);

        SDL_RenderPresent(renderer);

        SDL_Delay(speedtime);

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


        for(int i=2;i<snakepoint;i++){
            if(cycle[i].x==cycle[0].x&&cycle[i].y==cycle[0].y){
                dem++;
            }
        }
    }
}


void Menurunning(SDL_Renderer* renderer, SDL_Texture* texture2, SDL_Rect SourceRect2, SDL_Rect desRect2){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture2, &SourceRect2, &desRect2);
    SDL_RenderPresent(renderer);
}

