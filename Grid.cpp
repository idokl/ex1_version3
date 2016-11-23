#include "Grid.h"
#include "Point.h"

using namespace std;

Grid::Grid(int m, int n) {
    width = m;
    height = n;
    for (int i = 0; i < width; i++) {
        vector<Node> verticalVectorOfPoints = vector<Node>();
        for (int j = 0; j < height; j++) {
            Point p = Point(i, j);
            verticalVectorOfPoints.push_back(p);
        }
        vectorOfVerticalVectors.push_back(verticalVectorOfPoints);
    }
};

Grid::Grid(const Grid &grid) {
    width = grid.width;
    height = grid.height;
    vectorOfVerticalVectors = grid.vectorOfVerticalVectors;
}


queue<Node>* Grid::getNeighbors(Node p) {
    Point pNew = *((Point *)p.getValue());
    int x = pNew.getX();
    int y = pNew.getY();
    queue<Node>* neighbors = new queue<Node>();
    //if the point isn't in the graph, return null queue
    if ((x < 0) || (y < 0) || (x >= width) || (y >= height))
        return neighbors;
    if (x > 0)
        neighbors->push(this->vectorOfVerticalVectors[x-1][y]);
    if (y + 1 < height)
        neighbors->push(this->vectorOfVerticalVectors[x][y+1]);
    if (x + 1 < width)
        neighbors->push(this->vectorOfVerticalVectors[x+1][y]);
    if (y > 0)
        neighbors->push(this->vectorOfVerticalVectors[x][y-1]);
    return neighbors;
}

Grid::~Grid() {
}