/*
 * This Algorithm maintain graph that contains Points and edges.
 * It enables to find the shortest path between every 2 Points in the graph.
 * the BFS algorithm (=Breadth-first search) does it by building of tree that the startPoint is
 * its root and its neighbors are its sons. the BFS find all the points that the distance between
 * them to the startPoint is 1, then 2, then 3, etc.
 * When the BFS encounters the endPoint, it stop and return stack with all points in the shortest
 * path between startPoint to endPoint.
 */

#ifndef EX1_BFS_H
#define EX1_BFS_H

using  namespace std;

#include <map>
#include <queue>
#include <set>
#include <stack>
#include "Node.h"
#include "Grid.h"

template <class T>
class BfsAlgorithm {
private:
    //The graph that the BFS algorithm work on
    Graph<T>* graph;
public:
    //constructor
    BfsAlgorithm(Graph<T>* graph);
    //return stack that maintains the points in the shortest path from "start" to "end".
    //(if no path from start to end, return empty stack).
    stack<Node<T>> navigate( Node<T> &start, Node<T> &end);
};


template <class T>
BfsAlgorithm<T>::BfsAlgorithm(Graph<T> *graph) : graph(graph) {
    graph = graph;
}

template <class T>
stack<Node<T>> BfsAlgorithm<T>::navigate(Node<T> &start, Node<T> &end) {
    //initialization of variables
    //stack for the shortest path (between the given points) that this function will return
    stack<Node<T>> path = stack<Node<T>>();
    bool pathHasBeenFound = false;
    //queue that maintain points that are candidates to look for their neighbors
    //(in order to find access to new points)
    queue<Node<T>> pointsToLookForNeighbors = queue<Node<T>>();
    //set of points that have already been visited in this search
    //(we have already know the shortest path from the start Node to them)
    set<Node<T>> visitedPoints = set<Node<T>>();
    //map that match to every visitedPoint its parent in the tree that the BFS build
    map<Node<T>, Node<T>> parentOfPoint = map<Node<T>, Node<T>>();
    //map that match to every visitedPoint its distance from the start Node
    map<Node<T>, int> distanceOfPoint = map<Node<T>, int>();
    //(we could implement the function without the "visitedPoints" set and the "distanceOfPoint"
    //map, but it might be useful in the future)

    //enter the start Node to the queue and start to build the search tree by it
    distanceOfPoint.insert(pair<Node<T>,int>(start, 0));
    pointsToLookForNeighbors.push(start);

    while(!pointsToLookForNeighbors.empty()) {
        //take out a Node from the queue and check its distance and its neighbors
        Node<T> current = pointsToLookForNeighbors.front();
        pointsToLookForNeighbors.pop();
        int currentDistance = distanceOfPoint.at(current);
        queue<Node<T>> currentNeighbors = graph->getNeighbors(current);
        //for each neighbor: check whether it has been visited.
        //if not, add it to our queue.
        while (!currentNeighbors.empty()) {
            Node<T> neighbor = currentNeighbors.front();
            currentNeighbors.pop();
            bool theNeighborHasBeenVisited = (visitedPoints.find(neighbor) != visitedPoints.end());
            if (!theNeighborHasBeenVisited) {
                visitedPoints.insert(neighbor);
                parentOfPoint.insert(pair<Node<T>,Node<T>>(neighbor, current));
                distanceOfPoint.insert(pair<Node<T>,int>(neighbor, currentDistance + 1));
                pointsToLookForNeighbors.push(neighbor);
            }
            //if we found the end Node, enter it to the stack with all its ancestors,
            //(and then break the loop and return this stack)
            if (neighbor == end) {
                pathHasBeenFound = true;
                path.push(neighbor);
                Node<T> previousPointOfPath = neighbor;
                do {
                    previousPointOfPath = parentOfPoint.at(previousPointOfPath);
                    path.push(previousPointOfPath);
                } while (!(previousPointOfPath == start));
                break;
            }
        }
        //delete currentNeighbors;
        if (pathHasBeenFound)
            break;
    }
    return path;
}

#endif //EX1_BFS_H