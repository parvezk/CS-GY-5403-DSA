
#include "magic.h"

Magic::Magic(){
    
    size = 0;
}

Magic::~Magic(){

    delete []number;
}


int Magic::getSize(){
    return size;
}

void Magic::setSize(int newSize){
    
    if(newSize>0){

        size = newSize;

        initNumber();
    }
}


int Magic::getNumber(int x, int y){

    if(size>0 && x<size && x>=0 && y<size && y>=0)

        return number[y*size+x];
    else
        return -1;
}

void Magic::setNumber(int x, int y, int newNumber){

    if(size>0 && x<size && x>=0 && y<size && y>=0)
        
        number[y*size+x] = newNumber;
}

void Magic::initNumber(){

    if(size>0){

        if(number!=0)
            delete []number;
        
        number = new int(size*size);

        for(int y=0; y<size; y++)
            for(int x=0; x<size; x++)
                number[y*size+x] = -1;
    }
}
