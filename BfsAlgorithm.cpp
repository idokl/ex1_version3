#include <map>
#include "BfsAlgorithm.h"

BfsAlgorithm::BfsAlgorithm(Graph *&theGraph) {
    graph = theGraph;
}

stack<Point> BfsAlgorithm::navigate(Point start, Point end) {
    //initialization of variables
    //stack for the shortest path (between the given points) that this function will return
    stack<Point> path = stack<Point>();
    bool pathHasBeenFound = false;
    //queue that maintain points that are candidates to look for their neighbors
    //(in order to find access to new points)
    queue<Point> pointsToLookForNeighbors = queue<Point>();
    //set of points that have already been visited in this search
    //(we have already know the shortest path from the start Point to them)
    set<Point> visitedPoints = set<Point>();
    //map that match to every visitedPoint its parent in the tree that the BFS build
    map<Point, Point> parentOfPoint = map<Point, Point>();
    //map that match to every visitedPoint its distance from the start Point
    map<Point, int> distanceOfPoint = map<Point, int>();
    //(we could implement the function without the "visitedPoints" set and the "distanceOfPoint"
    //map, but it might be useful in the future)

    //enter the start Point to the queue and start to build the search tree by it
    distanceOfPoint.insert(pair<Point,int>(start, 0));
    pointsToLookForNeighbors.push(start);

    while(!pointsToLookForNeighbors.empty()) {
        //take out a Point from the queue and check its distance and its neighbors
        Point current = pointsToLookForNeighbors.front();
        pointsToLookForNeighbors.pop();
        int currentDistance = distanceOfPoint.at(current);
        queue<Point>* currentNeighbors = graph->getNeighbors(current);
        //for each neighbor: check whether it has been visited.
        //if not, add it to our queue.
        while (!currentNeighbors->empty()) {
            Point neighbor = currentNeighbors->front();
            currentNeighbors->pop();
            bool theNeighborHasBeenVisited = (visitedPoints.find(neighbor) != visitedPoints.end());
            if (!theNeighborHasBeenVisited) {
                visitedPoints.insert(neighbor);
                parentOfPoint.insert(pair<Point,Point>(neighbor, current));
                distanceOfPoint.insert(pair<Point,int>(neighbor, currentDistance + 1));
                pointsToLookForNeighbors.push(neighbor);
            }
            //if we found the end Point, enter it to the stack with all its ancestors,
            //(and then break the loop and return this stack)
            if (neighbor == end) {
                pathHasBeenFound = true;
                path.push(neighbor);
                Point previousPointOfPath = neighbor;
                do {
                    previousPointOfPath = parentOfPoint.at(previousPointOfPath);
                    path.push(previousPointOfPath);
                } while (!(previousPointOfPath == start));
                break;
            }
        }
        delete currentNeighbors;
        if (pathHasBeenFound)
            break;
    }
    return path;
}