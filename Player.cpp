#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myFSMMode = STOP;

    // more actions to be included
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol = '@';

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
    if(input!='\0'){
        switch(input)
        {     
            case 27: // Escape key to exit
                mainGameMechsRef->setExitTrue();
                break;                 
            case 'w':  // up
                if (myFSMMode != DOWN) {  
                    myFSMMode = UP;
                }
                break;

            case 'a':  // left
                if (myFSMMode != RIGHT) {  
                    myFSMMode = LEFT;
                }
                break;
            case 's':  // down
                if (myFSMMode != UP) {  
                    myFSMMode = DOWN;
                }   
                break;
            case 'd':  // right
                if (myFSMMode != LEFT) {  
                    myFSMMode = RIGHT;
                }
                break;
            default:
                myFSMMode = STOP;
                break;
        }
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


    if (playerPos.pos->x < 1) {
        playerPos.pos->x = (mainGameMechsRef->getBoardSizeX() - 2);
    }
    else if (playerPos.pos->x > mainGameMechsRef->getBoardSizeX()-2) {
        playerPos.pos->x = 1;
    }

    if (playerPos.pos->y < 1) {
        playerPos.pos->y = (mainGameMechsRef->getBoardSizeY() - 2);
    }
    else if (playerPos.pos->y > (mainGameMechsRef->getBoardSizeY()-2)) {
        playerPos.pos->y = 1;
    }

}

// More methods to be added
int Player::getmyFSMmode(){
    return myFSMMode;
}