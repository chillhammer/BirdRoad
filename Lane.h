#ifndef LANE_H
#define LANE_H
#include "Vector2D.h"
class Lane{
private:
	double initDirection;
public:
    Lane(){}
	Lane(double dir){ initDirection = dir; }
	double getDirection(){ return initDirection; }

    virtual Vector2D getEntrance(){return Vector2D(0,0);};
	virtual Vector2D getExit(){return Vector2D(0,0);};

	virtual Vector2D getEntrance(int){return Vector2D(0,0);};
	virtual Vector2D getExit(int){return Vector2D(0,0);};
};

#endif
