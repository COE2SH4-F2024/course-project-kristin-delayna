#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food{
    private:
        objPos food;
        int xLim;
        int yLim;

    public:
        Food();
        Food(int boardSizeX, int boardSizeY);
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        objPos getFoodPos() const;



};


#endif

