#ifndef AVENUE_H
#define AVENUE_H
#include "Lane.h"
#include "Vector2D.h"

class Avenue : public Lane{
private:
	static const int HEIGHT = 1;
	static const int STOPLIGHTS = 1;
	Vector2D entrance;
	Vector2D exit;
	double intersection;
public:
    Avenue(){};
	Avenue(Vector2D, Vector2D, double, double);

    Vector2D getEntrance();
	Vector2D getExit();

	Vector2D getEntrance(int);
	Vector2D getExit(int);

};


#endif
