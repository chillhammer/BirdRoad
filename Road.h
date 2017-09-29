#ifndef ROAD_H
#define ROAD_H
#include "Lane.h"
#include "Vector2D.h"

class Road : public Lane{
private:
	static const int HEIGHT = 2;
	static const int STOPLIGHTS = 3;
	static const double LANE_LENGTH = 15;
	static const double INTERSECTION_LENGTH = 7;
	Vector2D entrances[HEIGHT];
	Vector2D exits[HEIGHT];
	double intersections[STOPLIGHTS];
public:
    Road(){};
	Road(Vector2D, Vector2D, double, double);

	Vector2D getEntrance();
	Vector2D getExit();

	Vector2D getEntrance(int);
	Vector2D getExit(int);

};


#endif
