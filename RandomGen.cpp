#include "RandomGen.h"
#include <time.h>
#include <stdlib.h>


//Constructor
RandomGen::RandomGen(){
    srand(time(0));
}

//Destructor
RandomGen::~RandomGen(){

}

//returns static instace
RandomGen* RandomGen::Instance(){
    RandomGen static rg;
    return &rg;
}

//gives back random number (int or double or float)
int RandomGen::rInt(int n){
	return static_cast<int>(rand() % n);
}