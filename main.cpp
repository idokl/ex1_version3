#include <string>
#include <iostream>
#include "Node.h"
#include "Grid.h"
#include "BfsAlgorithm.h"
#include "InputParsing.h"

using namespace std;

int main(int argc, char* argv[]) {

    //scan input string (gridWidth_gridHeight,startX_startY,endX_endY) and parse it
    string inputString;
    getline(cin, inputString);
    InputParsing ip = InputParsing(inputString);

    Node<Point> startPoint(Point(ip.getsourcePointX(), ip.getsourcePointY()));
    Node<Point> endPoint(Point(ip.getdestinationPointX(),ip.getdestinationPointY()));
    Graph<Point>* g = new Grid(ip.getgridWidth(), ip.getgridHeight());
    BfsAlgorithm<Point> bfs(g);

    //finding the short path from startPoint to endPoint
    stack<Node<Point>> idealPath = bfs.navigate(startPoint, endPoint);
    //print the path
    while (!idealPath.empty()) {
        Node<Point> nodeOfIdealPath = idealPath.top();
        idealPath.pop();
        Point pointOfIdealPath = nodeOfIdealPath.getValue();
        cout << pointOfIdealPath << endl;
    }
    delete g;
return 0;
}