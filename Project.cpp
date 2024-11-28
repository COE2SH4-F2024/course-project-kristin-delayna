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
    game = new GameMechs(20,10);
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

    for(i=0;i<ySize;i++)
    {
        for(j=0;j<xSize;j++)
        {
            if(i==0 || i == ySize-1)
            {
                MacUILib_printf("#");
            }
            else if(j==0 ||j == xSize-1)
            {
                MacUILib_printf("#");
            }
            else if(i== playerPos.pos->y &&j == playerPos.pos->x)
            {
                MacUILib_printf("%c",playerPos.symbol);
            }
            else if(k<2 && i== objects[k].pos->y &&j == objects[k].pos->x)
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
    MacUILib_printf("Player Position: %d %d\n",playerPos.pos->x,playerPos.pos->y);
    MacUILib_printf("myFSMMode (UP, DOWN, LEFT, RIGHT, STOP): %d",myPlayer->getmyFSMmode());
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
