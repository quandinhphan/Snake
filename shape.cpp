#include "shape.h"

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
                m=m-0.001;
        }
    }
}

void eating(Cycle &a, Cycle &rand, int &point, int &runtime){
    if(a.x==rand.x&&a.y==rand.y){
        point++;
        runfaster(runtime);
        rand.createFood();
    }
}
