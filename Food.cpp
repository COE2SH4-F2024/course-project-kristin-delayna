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
    delete[] foodBucket;
    
}

void Food::generateFood(objPosArrayList* blockOff)
{
    int z;
    bool fine;
    objPos foodPos;
    for(z = 0; z < 3; z++)
    {
        do
        {   
            fine = true;
            int randomx = (rand() % (xLim-2))+1;
            int randomy = (rand() % (yLim-2))+1;

            foodPos.setObjPos(randomx,randomy,'a');

            for(int j = 0; j< foodBucket->getSize(); j++)
            {
                objPos foodi = foodBucket->getElement(j);
                if(foodPos.isPosEqual(&foodi))
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

int R;
    for(R = 0; R < 1; R++)
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
        
            // int randomx = (rand() % (xLim-2))+1;
            // int randomy = (rand() % (yLim-2))+1;
            // fine = true;
            // for(z=0;z<blockOff->getSize();z++){
            //     objPos cur = blockOff->getElement(z);
            //     if(foodPos.isPosEqual(&cur) && bitVector[randomy][randomx] != 0)
            //     {
            //         fine = false;
            //     }
            // }
            // if(fine == true)
            // {
            //     bitVector[randomy][randomx]++;
            //     unique++;
            // }
 
    // }
    // int i, j;
    // for(i = 0; i < yLim+1; i++)
    // {
    //     for(j = 0; j < xLim+1; j++)
    //     {
    //         if(bitVector[i][j] != 0)
    //         {
    //             foodPos.setObjPos(j, i, 'x');  

    //             foodBucket->insertHead(foodPos);  
    //         }
    //     }
    // }



objPos Food::getFoodPos(int index) const
{
    return foodBucket->getElement(index);
}

objPosArrayList* Food::getFoodArrayList() const
{
    return foodBucket;
}