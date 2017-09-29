//vehicle implemetation
#include "Vehicle.h"
#include <iostream>
#include <sstream>
#include "EntityManager.h"
#include "GameMap.h"

void Vehicle::update(){

    //removes old copy so that new one can be updated
    //mvwaddch(gMap->Window(),position.Y()+1,position.X()+1,' ');
    gMap->drawChar(position.X(), position.Y(), ' ');

    //update velocity
    velocity = std::min(
                    (velocity.createLine(maxSpeed,facing)),

                    (velocity+Vector2D(accSpeed,facing))

                    ); //creates line based off of speed variables

    //checks if vehicle is in front
    if(entManager->checkPosition(position+velocity)){
        velocity = Vector2D(0,0);
    }



    //update position
    position+= velocity;

    //draw();
    //gMap->drawChar(position.X(), position.Y(), ' ');
};




//Constructors/////////////////////////////////////////////////
    Vehicle::Vehicle() : BaseGameEntity(){
        maxSpeed = 1;
        velocity = Vector2D(0,0);
        facing = 0;
        accSpeed = 0.5;
        reactionTime = 0;

    };


    //Constructor with basic practically constants
    Vehicle::Vehicle(double x, double y, char m, double accSpeed,
                     double maxSpeed, double reactionTime)
        : BaseGameEntity(x,y,m){

        this->accSpeed = accSpeed;
        this->maxSpeed = maxSpeed;
        this->reactionTime = reactionTime;

        velocity = Vector2D(0,0);
        facing = 0;
    }

    //Constructor with initial velocity
    ///Vehicle(x, y, model, acceleration, maxSpeed, reactionTime, initVelocity, initDirection);
    Vehicle::Vehicle(double x, double y, char m, double accSpeed,
                     double maxSpeed, double reactionTime, Vector2D initSpeed, double dir)
        : BaseGameEntity(x,y,m){

        this->accSpeed = accSpeed;
        this->maxSpeed = maxSpeed;
        this->reactionTime = reactionTime;

        velocity = initSpeed;
        facing = dir;
    }
