/*
 * Grid is a graph represents matrix of points in the plane.
 * The matrix size is m*n (m columns and n rows).
 * Its first Point is (0,0). Its last Point is (m-1,n-1).
 */

#ifndef EX1_GRID_H
#define EX1_GRID_H

#include "Point.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Grid: public Graph {
private:
    int width;
    int height;
    vector< vector<Point> > vectorOfVerticalVectors;
public:
    //constructor. m is the grid width, n is the grid height.
    Grid(int m,int n);
    //copy constructor
    Grid(const Grid &grid);
    //destructor
    ~Grid();
    //return queue of Points in the grid that are next to the Point p (four points at most)
    //the neighbors order is: left, up, right and down.
    queue<Point>* getNeighbors(Point p);
};


#endif //EX1_GRID_H
