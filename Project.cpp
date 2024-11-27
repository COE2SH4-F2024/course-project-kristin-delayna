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

objPos objects[2];

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
    objects[0] = objPos(2,4,'a');
    objects[1] = objPos(3,6,'g');
    
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{

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
