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
    stack<Node<T>> navigate(Node<T> &start, Node<T> &end);
};

#endif //EX1_BFS_H