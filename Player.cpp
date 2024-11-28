#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myFSMMode = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'@');

}


Player::~Player()
{
    // delete any heap members here
    
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic
    char input = mainGameMechsRef->getInput();

    switch(input)
    {     
        case 27:
            mainGameMechsRef->setExitTrue();
            break;                 
        case 'w':  //up
            if(myFSMMode == LEFT||myFSMMode==RIGHT||myFSMMode==STOP){
                myFSMMode=UP;
            }
            break;

        case 'a':  //left
            if(myFSMMode == UP||myFSMMode==DOWN||myFSMMode==STOP){
                myFSMMode=LEFT;
            }
            break;
        case 's':  //down
            if(myFSMMode == LEFT||myFSMMode==RIGHT||myFSMMode==STOP){
                myFSMMode=DOWN;
            }   
            break;
        case 'd':  //right
            if(myFSMMode == UP||myFSMMode==DOWN||myFSMMode==STOP){
                myFSMMode=RIGHT;
            }
            break;
    }




}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if(myFSMMode==LEFT){
        playerPos.pos->x--;
    }
    else if(myFSMMode==RIGHT){
        playerPos.pos->x++;
    }
    else if(myFSMMode==UP){
        playerPos.pos->y--;
    }
    else if(myFSMMode==DOWN){
        playerPos.pos->y++;
    }
    else if(myFSMMode==STOP){
        playerPos.pos->x =(mainGameMechsRef->getBoardSizeX()/2);
        playerPos.pos->y =(mainGameMechsRef->getBoardSizeY()/2);
    }


    if (playerPos.pos->x < 0) {
        playerPos.pos->x = (mainGameMechsRef->getBoardSizeX() - 2);
    }
    else if (playerPos.pos->x >= mainGameMechsRef->getBoardSizeX()) {
        playerPos.pos->x = 1;
    }

    if (playerPos.pos->y < 0) {
        playerPos.pos->y = (mainGameMechsRef->getBoardSizeY() - 1);
    }
    else if (playerPos.pos->y >= mainGameMechsRef->getBoardSizeY()) {
        playerPos.pos->y = 1;
    }

}

// More methods to be added