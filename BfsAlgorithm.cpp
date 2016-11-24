#include <map>
#include "BfsAlgorithm.h"

BfsAlgorithm::BfsAlgorithm(Graph *theGraph) {
    graph = theGraph;
}

stack<Node> BfsAlgorithm::navigate(Node &start, Node &end) {
    //initialization of variables
    //stack for the shortest path (between the given points) that this function will return
    stack<Node> path = stack<Node>();
    bool pathHasBeenFound = false;
    //queue that maintain points that are candidates to look for their neighbors
    //(in order to find access to new points)
    queue<Node> pointsToLookForNeighbors = queue<Node>();
    //set of points that have already been visited in this search
    //(we have already know the shortest path from the start Node to them)
    set<Node> visitedPoints = set<Node>();
    //map that match to every visitedPoint its parent in the tree that the BFS build
    map<Node*, Node*> parentOfPoint = map<Node*, Node*>();
    //map that match to every visitedPoint its distance from the start Node
    map<Node, int> distanceOfPoint = map<Node, int>();
    //(we could implement the function without the "visitedPoints" set and the "distanceOfPoint"
    //map, but it might be useful in the future)

    //enter the start Node to the queue and start to build the search tree by it
    distanceOfPoint.insert(pair<Node,int>(start, 0));
    pointsToLookForNeighbors.push(start);

    while(!pointsToLookForNeighbors.empty()) {
        //take out a Node from the queue and check its distance and its neighbors
        Node current = pointsToLookForNeighbors.front();
        pointsToLookForNeighbors.pop();
        int currentDistance = distanceOfPoint.at(current);
        queue<Node>* currentNeighbors = graph->getNeighbors(current);
        //for each neighbor: check whether it has been visited.
        //if not, add it to our queue.
        while (!currentNeighbors->empty()) {
            Node neighbor = currentNeighbors->front();
            currentNeighbors->pop();
            bool theNeighborHasBeenVisited = (visitedPoints.find(neighbor) != visitedPoints.end());
            if (!theNeighborHasBeenVisited) {
                visitedPoints.insert(neighbor);
                parentOfPoint.insert(pair<Node,Node>(neighbor, current));
                distanceOfPoint.insert(pair<Node,int>(neighbor, currentDistance + 1));
                pointsToLookForNeighbors.push(neighbor);
            }
            //if we found the end Node, enter it to the stack with all its ancestors,
            //(and then break the loop and return this stack)
            if (neighbor == end) {
                pathHasBeenFound = true;
                path.push(neighbor);
                Node previousPointOfPath = neighbor;
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