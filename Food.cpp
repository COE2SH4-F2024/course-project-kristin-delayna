#include "Food.h"


Food::Food(){
    foodBucket = new objPosArrayList();
    xLim = 20;
    yLim = 10;
    
}

Food::Food(int boardSizeX,int boardSizeY){
    foodBucket = new objPosArrayList();
    xLim = boardSizeX;
    yLim = boardSizeY;
}

Food::~Food(){
    delete foodBucket;
}

void Food::generateFood(objPosArrayList* blockOff)
{
    int z;
    bool fine;
    objPos foodPos; //this is a temporary position for food (its only added to food bucket if it doesnt overlap with any other object on the board)
    for(z = 0; z < 3; z++)
    {
        do
        {   
            fine = true;
            //generate random coordinates
            int randomx = (rand() % (xLim-2))+1;
            int randomy = (rand() % (yLim-2))+1;

            foodPos.setObjPos(randomx,randomy,'a');
            //make sure new food isnt on top of old food
            for(int j = 0; j< foodBucket->getSize(); j++)
            {
                objPos foodi = foodBucket->getElement(j);
                if(foodPos.isPosEqual(&foodi))
                {
                    fine = false;
                }
            }
            //make sure new food isn't on top of snake
            for(int i = 0; i<blockOff->getSize(); i++)
            {
                objPos cur = blockOff->getElement(i);
                if(foodPos.isPosEqual(&cur))
                {
                    fine = false;
                }
            }
        }
        while(fine == false); //keep repeating until all is fine (nothing overlaps)
        foodBucket->insertTail(foodPos); //insert the newly generated 'fine' foodPos into foodBucket
    }
    //this code repeats for all different objects on the game board (uses the same logic as above)
    int p;
    for(p = 0; p < 1; p++)
    {
        do
        {   
            fine = true;
            int randomx = (rand() % (xLim-2))+1;
            int randomy = (rand() % (yLim-2))+1;

            foodPos.setObjPos(randomx,randomy,'$');

            for(int j = 0; j< foodBucket->getSize(); j++)
            {
                objPos foodiadd = foodBucket->getElement(j);
                if(foodPos.isPosEqual(&foodiadd))
                {
                    fine = false;
                }
            }
            for(int i = 0; i<blockOff->getSize(); i++)
            {
                objPos cur = blockOff->getElement(i);
                if(foodPos.isPosEqual(&cur))
                {
                    fine = false;
                }
            }
        }
        while(fine == false);
        foodBucket->insertTail(foodPos);
    }

int r;
    for(r = 0; r < 1; r++)
    {
        do
        {   
            fine = true;
            int randomx = (rand() % (xLim-2))+1;
            int randomy = (rand() % (yLim-2))+1;

            foodPos.setObjPos(randomx,randomy,'X');

            for(int j = 0; j< foodBucket->getSize(); j++)
            {
                objPos foodiadd = foodBucket->getElement(j);
                if(foodPos.isPosEqual(&foodiadd))
                {
                    fine = false;
                }
            }
            for(int i = 0; i<blockOff->getSize(); i++)
            {
                objPos cur = blockOff->getElement(i);
                if(foodPos.isPosEqual(&cur))
                {
                    fine = false;
                }
            }
        }
        while(fine == false);
        foodBucket->insertTail(foodPos);
    }


}


objPos Food::getFoodPos(int index) const
{
    return foodBucket->getElement(index);
}

objPosArrayList* Food::getFoodArrayList() const
{
    return foodBucket;
}