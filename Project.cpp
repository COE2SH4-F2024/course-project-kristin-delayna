#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

objPos objects[2];
GameMechs* game;
Player* myPlayer;

int main(void)
{

    Initialize();

    while(game->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    game = new GameMechs(10,20);
    myPlayer = new Player(game);
    objects[0] = objPos(2,4,'a');
    objects[1] = objPos(3,6,'g');
    

}

void GetInput(void)
{
    if(MacUILib_hasChar())
    {
        char input = MacUILib_getChar();
        game->setInput(input);
    }
   
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    
}

void DrawScreen(void)
{
    objPos playerPos = myPlayer->getPlayerPos();
    int xSize = game->getBoardSizeX();
    int ySize = game->getBoardSizeY();
    int i,j, k = 0;

    MacUILib_clearScreen();

    for(i=0;i<xSize;i++)
    {
        for(j=0;j<ySize;j++)
        {
            if(i==0 || i == xSize-1)
            {
                MacUILib_printf("#");
            }
            else if(j==0 ||j == ySize-1)
            {
                MacUILib_printf("#");
            }
            else if(i== playerPos.pos->x &&j == playerPos.pos->y)
            {
                MacUILib_printf("%c",playerPos.symbol);
            }
            else if(k<2 && i== objects[k].pos->x &&j == objects[k].pos->y)
            {
                MacUILib_printf("%c",objects[k].symbol);
                k++;
            }
            else
            {
                MacUILib_printf(" ");
            }
    
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Input: %c\n",game->getInput());

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
    //deletions for any new
    delete myPlayer;
    delete game;
}
