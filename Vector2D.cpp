//Vector Iimplementation
#include <math.h>
#include "Vector2D.h"

Vector2D Vector2D::createLine(double len, double dir){

    double x = 0;
    double y = 0;
    x = cos(dir*M_PI/180.0)*len;
    y = sin(dir*M_PI/180.0)*len;
    Vector2D temp(x,y);
    return temp;
}

Vector2D Vector2D::round(){
    return Vector2D(static_cast<int>(x),static_cast<int>(y));
}

//conditional operators
bool Vector2D::operator==(const Vector2D& right) const{
    return( (x==right.x) && (y==right.y) );
}

bool Vector2D::operator!=(const Vector2D& right) const{
    return( (x!=right.x) || (y!=right.y) );
}





//<=
bool Vector2D::operator<=(const Vector2D& right){

    bool result = (length()<= right.length());
    return result;
}

//>=
bool Vector2D::operator>=(const Vector2D& right){

    bool result = (length()<= right.length());
    return result;
}

//<
bool Vector2D::operator<(const Vector2D& right){

    bool result = (length()< right.length());
    return result;
}

//only for min()
bool operator<(const Vector2D& left, const Vector2D& right){

    bool result = (left.length()< right.length());
    return result;
}

//>
bool Vector2D::operator>(const Vector2D& right){

    bool result = (length()> right.length());
    return result;
}

//Equals operator
Vector2D& Vector2D::operator=(const Vector2D& right){
    x = right.x;
    y = right.y;

    return *this;
}

//PLUS
Vector2D Vector2D::operator+(const Vector2D& right) const{
    double newY = right.y + y;
    double newX = right.x + x;

    Vector2D temp(newX, newY);
    return temp;
}

//MINUS
Vector2D Vector2D::operator-(const Vector2D& right) const{
    double newY = x - right.y;
    double newX = y - right.x;

    Vector2D temp(newX, newY);
    return temp;
}

//PLUS EQUALS
Vector2D& Vector2D::operator+=(const Vector2D& right){
    x += right.x;
    y += right.y;
    return *this;
}

//MINUS EQUALS
Vector2D& Vector2D::operator-=(const Vector2D& right){
    x -= right.x;
    y -= right.y;
    return *this;
}


