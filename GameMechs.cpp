#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input = '\0';
    boardSizeX = 20;
    boardSizeY = 10;
    food.setObjPos(-10,-10, 'x');


}

GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input = '\0';
    boardSizeX = boardX;
    boardSizeY = boardY;
    food.setObjPos(-10,-10,'x');
    
}

// do you need a destructor?
GameMechs::~GameMechs()
{
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput()
{
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

void GameMechs::generateFood(objPos blockOff)
{
    int bitVector[boardSizeY+1][boardSizeX+1] = {0};
    int unique = 0;
    while(unique<1)
    {
        int randomx = (rand() % (getBoardSizeX()-2))+1;
        int randomy = (rand() % (getBoardSizeY()-2))+1;

        if(bitVector[randomy][randomx] == 0 && randomy != blockOff.pos->y && randomx != blockOff.pos->x)
        {
            bitVector[randomy][randomx]++;
            unique++; 
        }
    }
    int i, j;
    int k = 0;
    for(i = 0; i < boardSizeY+1; i++)
    {
        for(j = 0; j < boardSizeX+1; j++)
        {
            if(bitVector[i][j] != 0)
            {
                food.setObjPos(j, i, '*');
                k++;
            }
        }
    }

}
objPos GameMechs::getFoodPos() const
{
    return food;
}


// More methods should be added here