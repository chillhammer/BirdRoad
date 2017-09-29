#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <math.h>
#include <ncurses.h>


class Vector2D{

private:
    double x;
    double y;
public:

    //constructor
    Vector2D():x(0),y(0){}
    Vector2D(double a, double b):x(a),y(b){}

    //functions
    double X(){return x;}
    double Y(){return y;}
    double length() const{return sqrt(x*x + y*y);}
    Vector2D round();
    static Vector2D createLine(double, double); //creates line from dir and len

    //conditional operators
    bool operator==(const Vector2D&) const;
    bool operator!=(const Vector2D&) const;

    bool operator<=(const Vector2D&) ;
    bool operator>=(const Vector2D&) ;

    bool operator<(const Vector2D&) ;
    bool operator>(const Vector2D&) ;


    //other operator
    Vector2D& operator=(const Vector2D&);

    Vector2D operator+(const Vector2D&) const;
    Vector2D operator-(const Vector2D&) const;

    Vector2D& operator+=(const Vector2D&);
    Vector2D& operator-=(const Vector2D&);


};

//only for Min()
bool operator<(const Vector2D&, const Vector2D&) ;



#endif
