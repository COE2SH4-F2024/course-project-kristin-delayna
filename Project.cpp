#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include <time.h>
#include "Food.h"


using namespace std;

#define DELAY_CONST 100000


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


GameMechs* game;
Player* myPlayer;
Food* gameFood;

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
    srand(time(NULL));
    MacUILib_init();
    MacUILib_clearScreen();
    game = new GameMechs(20,10);
    myPlayer = new Player(game);
    gameFood = new Food(20,10);
    gameFood->generateFood(myPlayer->getPlayerPos());

}

void GetInput(void)
{
    
    if(MacUILib_hasChar())
    {
        char input = MacUILib_getChar();
        game->setInput(input);
        if(game->getInput()== 32)
        {
            gameFood->generateFood(myPlayer->getPlayerPos());
        }
    } 
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    
}

void DrawScreen(void)
{
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int xSize = game->getBoardSizeX();
    int ySize = game->getBoardSizeY(); 
    objPos foodPos = gameFood->getFoodPos();
    int i,j, k,l= 0;

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
            else if(j == foodPos.pos->x && i == foodPos.pos->y)
            {
                MacUILib_printf("%c",foodPos.symbol);
            }
            else
            {
                int found =0;
                for(k=0;k<playerPos->getSize();k++){
                    if(i == playerPos->getElement(k).getObjPos().pos->y && j== playerPos->getElement(k).getObjPos().pos->x){
                        MacUILib_printf("%c",playerPos->getElement(k).getSymbol());
                        found =1;
                    }
                }
                if (found==0){
                    MacUILib_printf(" ");
                }

                
            }
    
        }
        MacUILib_printf("\n");
    }
    //debugging
    MacUILib_printf("Input: %c\n",game->getInput());
    MacUILib_printf("Player Position: %d %d\n",playerPos->getHeadElement().pos->x,playerPos->getHeadElement().pos->y);
    MacUILib_printf("myFSMMode (UP, DOWN, LEFT, RIGHT, STOP): %d\n",myPlayer->getmyFSMmode());
    MacUILib_printf("Snake Size (will inc. when hit (3,5)): %d\n",playerPos->getSize());
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
    delete gameFood;
}
