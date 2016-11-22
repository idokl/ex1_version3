#include "Point.h"

using namespace std;

Point::Point(int xCoord, int yCoord): x(xCoord), y(yCoord) {
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

bool Point::operator==(const Point &p1) const {
    return((x==p1.x)&&(y==p1.y));
}

bool Point::operator<(const Point &p1) const {
    if ((x < p1.x) || ((x == p1.x) && (y < p1.y)))
        return true;
    else
        return false;
}

ostream& operator <<(ostream& os, const Point &point) {
    return os << "(" << point.x << "," << point.y << ")";
}