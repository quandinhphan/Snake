#include <iostream>
#include <SDL.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "Snake";

struct Box{
    int x;
    int y;
    int size=10;
    int stepX=5;
    int stepY=0;

    void render(SDL_Renderer* renderer){
        SDL_Rect filled_rect;
        filled_rect.x = x;
        filled_rect.y = y;
        filled_rect.w = size;
        filled_rect.h = size;
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); // green
        SDL_RenderFillRect(renderer, &filled_rect);
    }


    void move(){
        x+=stepX;
        y+=stepY;
        cout << stepX << "," << stepY << endl;
    }
     void moveup(){
        stepY=-5;
        stepX=0;
    }
    void movedown(){
        stepY=5;
        stepX=0;
    }
    void moveright(){
        stepY=0;
        stepX=5;
    }
    void moveleft(){
        stepY=0;
        stepX=-5;
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
};
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

void waitUntilKeyPressed();
int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    SDL_RenderClear(renderer);
    Box box;
    box.x=10;
    box.y=10;
    Box box2;
    SDL_Event e;

    while(true ){
        box.goback();
        box2.x=box.x;
        box2.y=box.y;
        box.move();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        box.render(renderer);
        box2.render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(10);

        if ( SDL_PollEvent(&e) == 0) continue;

        if (e.type == SDL_QUIT) break;

        if (e.type == SDL_KEYDOWN) {
        	switch (e.key.keysym.sym) {
        		case SDLK_ESCAPE: break;
        		case SDLK_LEFT: box.moveleft(); break;
            	case SDLK_RIGHT: box.moveright(); break;
            	case SDLK_DOWN:box.movedown(); break;
            	case SDLK_UP:box.moveup(); break;
        		default: break;
			}
        }
    }

    quitSDL(window, renderer);
    return 0;
}

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
