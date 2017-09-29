#include "EntityManager.h"
#include "GameMap.h"
#include "RandomGen.h"
#include "Road.h"
#include "Avenue.h"
#include "OtherVehicles.h"
#include <cassert>


//Constructor
EntityManager::EntityManager(){

}

//Destructor
EntityManager::~EntityManager(){

}

//returns static instace
EntityManager* EntityManager::Instance(){
    EntityManager static em;
    return &em;
}

//registers base game entity
void EntityManager::registerEntity(BaseGameEntity* bg){
	entMap.push_back(bg);
}


void EntityManager::spawnVehicle(){
    int vehicleType = randGen->rInt(3);


    double xstart = 0;
    double ystart = 0;
    double dir = 0;


    if(randGen->rInt(2) == 0){
        Road lane = gMap->getRoad();
        xstart = lane.getEntrance().X();
        ystart = lane.getEntrance().Y();
        dir = lane.getDirection();
    }else{
        Avenue lane = gMap->getAvenue();
        xstart = lane.getEntrance().X();
        ystart = lane.getEntrance().Y();
        dir = lane.getDirection();
    }


    switch(vehicleType){
        case 0: registerEntity( new Car(xstart, ystart, dir) ); break;
        case 1: registerEntity( new Truck(xstart, ystart, dir) ); break;
        case 2: registerEntity( new Motorcycle(xstart, ystart, dir) ); break;
    }

}


//drawing and updating all
void EntityManager::updateAll(){
    for(int i = 0; i<entMap.size(); i++ ){
        entMap.at(i)->update();
        if(entMap.at(i)->outOfRoom()){
            entMap.erase(entMap.begin()+i);
        }
    }
}

void EntityManager::drawAll(){
    for(int i = 0; i<entMap.size(); i++ ){
        entMap.at(i)->draw();
    }
}

//check position
bool EntityManager::checkPosition(Vector2D pos){

    for(int i = 0; i<entMap.size(); i++ ){
        if( entMap.at(i)->getPosition() == pos){
            return true;
        }
    }
    return false;
}
