#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"
#include <time.h>
#include "Food.h"
#include "objPosArrayList.h"


using namespace std;

#define DELAY_CONST 200000

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
    gameFood = new Food(20,10);
    myPlayer = new Player(game, gameFood);
    gameFood->generateFood(myPlayer->getPlayerPos());

}

void GetInput(void)
{
    
    game->getInput();
    
}

void RunLogic(void)
{
    myPlayer->updatePlayerDir();
    myPlayer->movePlayer();
    game->clearInput();
    
}

void DrawScreen(void)
{
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int xSize = game->getBoardSizeX();
    int ySize = game->getBoardSizeY(); 
    objPosArrayList* foodBucket = gameFood->getFoodArrayList();
    int i,j, k,l= 0;
    int p =0;

    MacUILib_clearScreen();
    MacUILib_printf("=========Snake Game=========\n");
    MacUILib_printf("Use 'wasd' to collect items\n'a' = 1 point\n");
    MacUILib_printf("'$' = 10 points\n'X' = Bomb (lose snake and points) \n");
    MacUILib_printf("Press 'tab' to pause game.\nPress 'escape' to end game.\n");

    for(i=0;i<ySize;i++)
    {
        for(j=0;j<xSize;j++)
        {
            if(i==0 || i == ySize-1) //draw border
            {
                MacUILib_printf("#");
            }
            else if(j==0 ||j == xSize-1) //draw border
            {
                MacUILib_printf("#");
            }
            else
            {
                bool foodprint = false; //draw food
                for(int p = 0; p<foodBucket->getSize();p++)
                {
                    objPos foodPos = foodBucket->getElement(p);
                    if(j == foodPos.pos->x && i == foodPos.pos->y)
                    {
                        MacUILib_printf("%c",foodPos.symbol);
                        foodprint = true;
                    }
                }
                if(!foodprint)//draw player
                {
                    int found = 0;
                    for(k=0;k<playerPos->getSize();k++){
                        if(i == playerPos->getElement(k).getObjPos().pos->y && j== playerPos->getElement(k).getObjPos().pos->x){
                            MacUILib_printf("%c",playerPos->getElement(k).getSymbol());
                            found =1;
                        }
                    }
                    if (found==0){
                        MacUILib_printf(" "); //draw spaces if nothing occupies that grid coordinate
                    }
                }
            }
    
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("Score: %d\n",game->getScore());
    MacUILib_printf("============================\n");
    

    //debugging
    // MacUILib_printf("================Debugging=================\n");
    // MacUILib_printf("Input: %c\n",game->getInput());
    // MacUILib_printf("Player Position: %d %d\n",playerPos->getHeadElement().pos->x,playerPos->getHeadElement().pos->y);
    // MacUILib_printf("myFSMMode (UP, DOWN, LEFT, RIGHT, STOP): %d\n",myPlayer->getmyFSMmode());
    // MacUILib_printf("Snake Size: %d\n",playerPos->getSize());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.2s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    if(game->getLoseFlagStatus()==true){
        MacUILib_printf("Collision! You Lost!\n");
    }
    if(game->getExitFlagStatus()==true){
        MacUILib_printf("Exiting game...\n");
    }
    MacUILib_uninit();
    //deletions for any new
    delete myPlayer;
    delete game;
    delete gameFood;

}
