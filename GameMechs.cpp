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


}

GameMechs::GameMechs(int boardX, int boardY)
{
    exitFlag = false;
    loseFlag = false;
    score = 0;
    input = '\0';
    boardSizeX = boardX;
    boardSizeY = boardY;
    
}

// do you need a destructor? 
//no because we didn't use any heap memory in this class
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
void GameMechs::Kaboom()
{
    score = 0;
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



// More methods should be added here