//
// Created by ohad on 23/11/16.
//


#include "Point.h"

Point::Point(int x, int y) : x(x),y(y){

}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

bool Point::isAvailable() {
    return true;
}


void* Point::getValue() {
    return this;
}
/*
bool Point::operator==(Node &other) {
    Point thisPoint = *((Point*)this->getValue());
    Point otherPoint = *((Point*)(other.getValue()));
    return(thisPoint.getX()==otherPoint.getX()) && (thisPoint.getY()==otherPoint.getY());
}

bool Point::operator<(Node &other) {
    Point thisPoint = *((Point*)this->getValue());
    Point otherPoint = *((Point*)(other.getValue()));
    if ((thisPoint.getX() < otherPoint.getX()) ||
            ((thisPoint.getX() == otherPoint.getX()) && (thisPoint.getY() < otherPoint.getY())))
        return true;
    else
        return false;
}
*/
bool Point::operator==(Point &other) {
    Point thisPoint = *((Point*)this->getValue());
    Point otherPoint = *((Point*)(other.getValue()));
    return(thisPoint.getX()==otherPoint.getX()) && (thisPoint.getY()==otherPoint.getY());
}

bool Point::operator<(const Point &other) const {
    /*
    Point thisPoint = *((Point*)this->getValue());
    Point otherPoint = *((Point*)(other.getValue()));
     */
    if ((x < other.x) ||
        (x == other.x && (y < other.y)))
        return true;
    else
        return false;
}

/*
ostream& operator <<(ostream& os, Node &point) {
    Point thePoint = *((Point*)(point.getValue()));
    return os << "(" << thePoint.getX() << "," << thePoint.getY() << ")";
}
*/

ostream& operator <<(ostream& os, Point &point) {
    return os << "(" << point.getX() << "," << point.getY() << ")";
}


