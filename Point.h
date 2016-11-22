/*
 * This class represents position of point in the plane.
 * It maintain the point's coordinates in the x axe and the y axe.
*/

#ifndef EX1_POINT_H
#define EX1_POINT_H

#include <iostream>

using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y);
    //return the x coordinate of this Point
    int getX();
    //return the y coordinate of this Point
    int getY();
    //return true if this Point is passable. false otherwise (=if there is an obstacle in this point).
    bool isAvailable();
    //Points comparison according to the x and y coordinates
    bool operator==(const Point &p1) const;
    //definition of ordering relation between Points in order to enable
    //data structures (like Map) to maintain them efficiently.
    //(the exact ordering relation, that we defined, doesn't matter)
    bool operator<(const Point &p1) const;
    //overloading operator to print this Point (by cout) in the format: (x,y)
    friend ostream& operator <<(ostream& os, const Point &point);
};


#endif //EX1_POINT_H
