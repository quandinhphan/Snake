#ifndef SHAPE_H
#define SHAPE_H

#include<bits/stdc++.h>
#include<SDL.h>
#include<SDL_image.h>
using namespace std;

const int xsquare=5;
const int ysquare=5;
const int wsquare=600-15;
const int hsquare=(600/2)-5;
const int rad=5;
const int stepchange=2*rad;

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
        SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
        SDL_RenderDrawRect(renderer, &filled_rect);
    }
};

void runfaster(int &m);

void eating(Cycle &a, Cycle &rand, int &point, int &runtime);

#endif // SHAPE_H
