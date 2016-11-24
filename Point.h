//
// Created by ohad on 23/11/16.
//

#ifndef EX1_VERSION_1_1_POINT_H
#define EX1_VERSION_1_1_POINT_H


#include "Node.h"

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y);
    //return the x coordinate of this Node
    int getX();
    //return the y coordinate of this Node
    int getY();
    //return true if this Node is passable. false otherwise (=if there is an obstacle in this point).
    bool isAvailable();

    void *getValue();
/*
    bool operator==(Node &other);

    bool operator<(Node &other);
*/
    bool operator<(Point &other);

    bool operator==(Point &other);
};


#endif //EX1_VERSION_1_1_POINT_H
