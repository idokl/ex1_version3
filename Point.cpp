//
// Created by ohad on 23/11/16.
//


#include "Point.h"

bool operator==(const Node &p1) const {
}

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

bool Node::operator==(const Node &p1) const {
    return((x==p1.x)&&(y==p1.y));
}

bool Node::operator<(const Node &p1) const {
    if ((x < p1.x) || ((x == p1.x) && (y < p1.y)))
        return true;
    else
        return false;
}

ostream& operator <<(ostream& os, const Node &point) {
    return os << "(" << point.x << "," << point.y << ")";
}