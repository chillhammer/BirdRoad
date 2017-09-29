#ifndef BASEGAMEENTITY_H
#define BASEGAMEENTITY_H

#include <ncurses.h>
#include "GameMap.h"
#include "Vector2D.h"

class BaseGameEntity{

private:
    int id;
    static int getNextValidID(){static int next = 0; return next++;}

protected:
    Vector2D position;
    char model;

public:
    //Constructor
    BaseGameEntity(int forcedID = getNextValidID()){
        id = forcedID; //otherwise default it to next valid
        model = '#';
    }

    BaseGameEntity(double x, double y, char m, int forcedID = getNextValidID()){

        position = Vector2D(x,y);
        id = forcedID;
        model = m;
    }

    virtual void update()=0;
    void draw(){
        gMap->drawChar(position.X(),position.Y(), model);
    };

    int ID(){return id;}
    Vector2D getPosition(){return position;}
    bool outOfRoom(){
        if(position.X() > gMap->mapWidth() || position.X() < 0 ||
            position.Y() > gMap->mapHeight() || position.Y() < 0)
                return true;

        return false;
    };


};


#endif
