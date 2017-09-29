#ifndef VEHICLE_H
#define VEHICLE_H

#include "BaseGameEntity.h"

class Vehicle : public BaseGameEntity{

private:

protected:
    double accSpeed;
    double maxSpeed;
    double facing; //angle
    Vector2D velocity;
    double reactionTime;

public:
    //Constructor
    Vehicle();


    //Constructor with basic practically constant
    Vehicle(double, double, char, double, double, double);

    //Constructor with initial velocity
    ///Vehicle(x, y, model, acceleration, maxSpeed, reactionTime, initVelocity, initDirection);
    Vehicle(double, double, char, double, double, double, Vector2D, double);

    //functions
    void update();

};


#endif
