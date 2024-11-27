#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    exitFlag = false;
    
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    objPos a = objPos(4,5,'2');

    int i,j, k = 0;
    MacUILib_clearScreen();
    for(i=0;i<10;i++)
    {
        for(j=0;j<20;j++)
        {
            if(i==0 || i == 9)
            {
                MacUILib_printf("#");
            }
            else if(j==0 ||j == 19)
            {
                MacUILib_printf("#");
            }
            else if(i== a.pos->x &&j == a.pos->y)
            {
                MacUILib_printf("%c",a.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
    
        }
        MacUILib_printf("\n");
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
