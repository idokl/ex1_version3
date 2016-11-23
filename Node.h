/*
 * This class represents position of point in the plane.
 * It maintain the point's coordinates in the x axe and the y axe.
*/

#ifndef EX1_POINT_H
#define EX1_POINT_H

#include <iostream>

using namespace std;

class Node {

public:
    //return the x coordinate of this Node
    int getX();
    //return the y coordinate of this Node
    int getY();
    //return true if this Node is passable. false otherwise (=if there is an obstacle in this point).
    bool isAvailable();
    //Points comparison according to the x and y coordinates
    virtual bool operator==(const Node &p1) const = 0;
    //definition of ordering relation between Points in order to enable
    //data structures (like Map) to maintain them efficiently.
    //(the exact ordering relation, that we defined, doesn't matter)
    virtual bool operator<(const Node &p1) const = 0;
    //overloading operator to print this Node (by cout) in the format: (x,y)
    friend ostream& operator <<(ostream& os, const Node &point);
    virtual void *getValue() = 0;
};


#endif //EX1_POINT_H
