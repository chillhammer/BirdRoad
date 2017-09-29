#include "Road.h"
#include "Avenue.h"
#include "RandomGen.h"




Road::Road(Vector2D topEntrance, Vector2D topExit, double leftStop, double initDir) : Lane(initDir){
	for(int i = 0; i<HEIGHT; i++){
		entrances[i] = topEntrance + Vector2D(0,i);
		exits[i]     = topExit     + Vector2D(0,i);
	}

	for(int i = 0; i<STOPLIGHTS; i++){
		intersections[i] = leftStop + (INTERSECTION_LENGTH + LANE_LENGTH)*i;
	}
}

//Random
Vector2D Road::getEntrance(){
	return entrances[randGen->rInt(HEIGHT)];
}

Vector2D Road::getExit(){
	return exits[randGen->rInt(HEIGHT)];
}


//Manual
Vector2D Road::getEntrance(int l){ 
	return entrances[l]; 
}

Vector2D Road::getExit(int l){
	return exits[l];
}


//AVENUE/////////
Avenue::Avenue(Vector2D ent, Vector2D ex, double inter, double initDir) : Lane(initDir){
	entrance = ent;
	exit = ex;
	intersection = inter;
}
//Since there is only one, no need for random
Vector2D Avenue::getEntrance(){
	return entrance;
}

Vector2D Avenue::getExit(){
	return exit;
}


//In case of templates....
Vector2D Avenue::getEntrance(int l){ 
	getEntrance();
}

Vector2D Avenue::getExit(int l){
	getExit();
}
