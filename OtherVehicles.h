#ifndef OTHERVEHICLES_H
#define OTHERVEHICLES_H

#include "Vehicle.h"

class Car : public Vehicle{

public:
    //Constructor with direction
    Car(double startx, double starty, double initDir){
        position = Vector2D(startx, starty);
        model = 'C';
        accSpeed = 0.0000010;
        maxSpeed = 0.0005;
        facing = initDir;
        velocity = velocity.createLine(maxSpeed, facing);
    };

};


class Motorcycle : public Vehicle{

public:
    //Constructor with direction
    Motorcycle(double startx, double starty, double initDir){
        position = Vector2D(startx, starty);
        model = 'M';
        accSpeed = 0.0000050;
        maxSpeed = 0.0007;
        facing = initDir;
        velocity = velocity.createLine(maxSpeed, facing);
    };

};


class Truck : public Vehicle{

public:
    //Constructor with direction
    Truck(double startx, double starty, double initDir){
        position = Vector2D(startx, starty);
        model = 'T';
        accSpeed = 0.00000002;
        maxSpeed = 0.00049;
        facing = initDir;
        velocity = velocity.createLine(maxSpeed, facing);
    };

};



#endif
