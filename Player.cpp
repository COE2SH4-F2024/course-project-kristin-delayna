#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef, Food* foodRef)
{
    mainGameMechsRef = thisGMRef;
    mainFoodRef = foodRef;
    myFSMMode = STOP;

    // more actions to be included
    playerPosList = new objPosArrayList();
    objPos startPos;
    startPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,mainGameMechsRef->getBoardSizeY()/2,'*');
    playerPosList->insertHead(startPos);
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
    
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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
            case 9: //Tab key to stop the snake (pause game)
                myFSMMode = STOP;
                break;
        }
    }
}


void Player::movePlayer()
{
    objPos move;
    objPosArrayList* foodBucket = mainFoodRef->getFoodArrayList();
    int xboard = mainGameMechsRef->getBoardSizeX();
    int yboard = mainGameMechsRef->getBoardSizeY();
    int index = 0;

    move.setObjPos(playerPosList->getHeadElement());

    // PPA3 Finite State Machine logic
    // this works by creating the objPos move. move is incremented with the direction we want the snake to move in and then added to the head of the snake
    // the tail is then deleted to make sure the snake stays the same size when just moving regularly
    // read more comments when the snake is not just moving regularly
    if(myFSMMode==LEFT){
        move.pos->x--;
        if(move.pos->x<1){
            move.pos->x = xboard-2;
        }
    }
    else if(myFSMMode==RIGHT){
        move.pos->x++;
        if(move.pos->x > xboard-2){
            move.pos->x = 1;
        }
    }
    else if(myFSMMode==UP){
        move.pos->y--;
        if(move.pos->y < 1){
            move.pos->y = yboard-2;
        }
    }
    else if(myFSMMode==DOWN){
        move.pos->y++;
        if(move.pos->y > yboard-2){
            move.pos->y = 1;
        }
    }
    else if(myFSMMode==STOP){
        return;
    }
    if(checkSelfCollision() == true) //checking to see if snake hit itself
    {
        mainGameMechsRef->setLoseFlag();
        mainGameMechsRef->setExitTrue();
    }

    //LOGIC FOR EATING FOOD
    bool foodEaten = false;
    for (int p = 0; p < foodBucket->getSize(); p++) {
        objPos foody = foodBucket->getElement(p); //current food that is being eaten
        if (move.isPosEqual(&foody)) {
            while(foodBucket->getSize()>0)
            {
                foodBucket->removeTail(); //delete the foodBucket list for next random generation
            } 
            mainFoodRef->generateFood(playerPosList); //regenerate foods
            if(foody.getSymbol() == '$') //if player eats money food, increment score by 10, increase snake length (by not deleting tail) and move snake forward
            {
                for(int i = 0; i<10; i++)
                {
                    mainGameMechsRef->incrementScore();
                }
                playerPosList->insertHead(move);
            }
            else if(foody.getSymbol() == 'X') //if player eats bomb food, reset score to 0 and reset snake length
            {
                mainGameMechsRef->Kaboom();
                int size = playerPosList->getSize();
                for(int d = 0; d < size -1;d++)
                    {
                        playerPosList->removeTail();
                    }
            }       
            else //regular eating (increase score by 1), increase length of snake (by not deleting tail)
            {
                mainGameMechsRef->incrementScore();
                playerPosList->insertHead(move);
            }
            foodEaten = true;
        }
    }
    if (foodEaten == false && myFSMMode != STOP) {// regular movement tail deletion
        playerPosList->insertHead(move);  
        playerPosList->removeTail(); 
    }
}
// More methods to be added
int Player::getmyFSMmode()// used for debugging
{
    return myFSMMode; 
}
bool Player::checkSelfCollision(){ //return true if player hits themselves (lose) otherwise false
    if(myFSMMode!=STOP){
        for(int i=1;i<playerPosList->getSize();i++){
            if(playerPosList->getHeadElement().pos->x == playerPosList->getElement(i).pos->x && playerPosList->getHeadElement().pos->y == playerPosList->getElement(i).pos->y){
                return true;
            }
        }
    }
    else{
        return false;
    }
    
}