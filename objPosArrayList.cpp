#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    aList = new objPos[ARRAY_MAX_CAP];
    for(int i=0;i<listSize;i++){ //initializing every objPos() in the arraylist
        aList[i] = objPos();
    }
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    //making sure you cant add a head if the list is over its capacity
    if(listSize>=arrayCapacity)return;
    //insert Head code (copy everything back one index(start from the back) and insert head in resultant empty space)
    for(int i = listSize;i>0;i--){
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    listSize++;
    
}

void objPosArrayList::insertTail(objPos thisPos)
{
    //indexing check(cant insert if over capacity)
    if(listSize>=arrayCapacity){
        return;
    }
    //insert tail at the end of list
    aList[listSize] = thisPos;
    listSize++;
    
}

void objPosArrayList::removeHead()
{
    //cant remove head if list is 0
    if(listSize == 0) return;
    //if list is only 1 item long
    else if(listSize==1){
        aList[0] = objPos();
        listSize--;
        return;
    }
    //copy rest of list down to overwrite head
    for(int i = 1; i < listSize ; i++){
        aList[i-1] = aList[i];
    }
        
    aList[listSize-1] = objPos();
    listSize--;
    
}

void objPosArrayList::removeTail()
{
    //if we reduce list size, the tail is not included in the list (deleting tail)
    if(listSize > 0)
        listSize--;
    
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
    
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
    
}

objPos objPosArrayList::getElement(int index) const
{
    if(index < 0){
        index=0;
    }
    if(index>listSize){
        return aList[listSize];
    }

    return aList[index];
    
}
