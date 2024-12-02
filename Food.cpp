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
    int bitVector[yLim+1][xLim+1] = {0};
    int unique = 0,z;
    bool fine;
    while(unique<5)
    {
        do
        {
            int randomx = (rand() % (xLim-2))+1;
            int randomy = (rand() % (yLim-2))+1;
            fine = true;
            for(z=0;z<blockOff->getSize();z++){
                if(!(bitVector[randomy][randomx] == 0 && randomy != blockOff->getElement(z).getObjPos().pos->y && randomx != blockOff->getElement(z).getObjPos().pos->x))
                {
                    fine = false;
                    break;
                }
            }
            if(fine == true)
            {
                bitVector[randomy][randomx]++;
                unique++;
            }
    
        }
        while(fine == false);


        
    }
    int i, j;
    for(i = 0; i < yLim+1; i++)
    {
        for(j = 0; j < xLim+1; j++)
        {
            if(bitVector[i][j] != 0)
            {
                objPos foodPos;
                foodPos.setObjPos(j, i, 'x');  

                foodBucket->insertTail(foodPos);  
            }
        }
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