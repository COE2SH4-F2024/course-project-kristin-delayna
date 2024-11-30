#include "Food.h"


Food::Food(){
    objPos foodPos;
    food.setObjPos(-10,-10, 'x');
    xLim = 20;
    yLim = 10;
    
}

Food::Food(int boardSizeX,int boardSizeY){
    objPos foodPos;
    food.setObjPos(-10,-10, 'x');
    xLim = boardSizeX;
    yLim = boardSizeY;
}

Food::~Food(){
    
}

void Food::generateFood(objPosArrayList* blockOff)
{
    int bitVector[yLim+1][xLim+1] = {0};
    int unique = 0,z;
    while(unique<1)
    {
        int randomx = (rand() % (xLim-2))+1;
        int randomy = (rand() % (yLim-2))+1;

        for(z=0;z<blockOff->getSize();z++){
            if(bitVector[randomy][randomx] == 0 && randomy != blockOff->getElement(z).getObjPos().pos->y && randomx != blockOff->getElement(z).getObjPos().pos->x)
            {
                bitVector[randomy][randomx]++;
                unique++; 
            }
        }
        
    }
    int i, j;
    int k = 0;
    for(i = 0; i < yLim+1; i++)
    {
        for(j = 0; j < xLim+1; j++)
        {
            if(bitVector[i][j] != 0)
            {
                food.setObjPos(j, i, 'x');
                k++;
            }
        }
    }

}


objPos Food::getFoodPos() const
{
    return food;
}