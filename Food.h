#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;

class Food{
    private:
        int xLim;
        int yLim;
        objPosArrayList* foodBucket;

    public:
        Food();
        Food(int boardSizeX, int boardSizeY);
        ~Food();

        void generateFood(objPosArrayList* blockOff);
        objPos getFoodPos(int index) const;
        objPosArrayList* getFoodArrayList() const;



};


#endif

