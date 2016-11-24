#include <string>
#include <iostream>
#include "Node.h"
#include "Grid.h"
#include "BfsAlgorithm.h"
#include "Point.h"

using namespace std;

int main() {
    //scan input string (gridWidth_gridHeight,startX_startY,endX_endY) and parse it
    string inputString;
    getline(cin, inputString);

    string gridWidthString, gridHeightString;
    string sourcePointXString, sourcePointYString;
    string destinationPointXString, destinationPointYString;

    //parsing of the input
    string::size_type commaPosition = inputString.find(",");
    string gridSize = inputString.substr(0, commaPosition);
    string sourceAndDestinationPoints = inputString.substr(commaPosition + 1);
    commaPosition = sourceAndDestinationPoints.find(",");
    string sourcePointString = sourceAndDestinationPoints.substr(0, commaPosition);
    string destinationPointString = sourceAndDestinationPoints.substr(commaPosition + 1);
    string::size_type underlinePosition = gridSize.find("_");
    gridWidthString = gridSize.substr(0, underlinePosition);
    gridHeightString = gridSize.substr(underlinePosition + 1);
    underlinePosition = sourcePointString.find("_");
    sourcePointXString = sourcePointString.substr(0, underlinePosition);
    sourcePointYString = sourcePointString.substr(underlinePosition + 1);
    underlinePosition = destinationPointString.find("_");
    destinationPointXString = destinationPointString.substr(0, underlinePosition);
    destinationPointYString = destinationPointString.substr(underlinePosition + 1);

    int gridWidth = stoi(gridWidthString);
    int gridHeight = stoi(gridHeightString);
    int sourcePointX = stoi(sourcePointXString);
    int sourcePointY = stoi(sourcePointYString);
    int destinationPointX = stoi(destinationPointXString);
    int destinationPointY = stoi(destinationPointYString);

    Node<Point> startPoint(Point(sourcePointX, sourcePointY));
    Node<Point> endPoint(Point(destinationPointX,destinationPointY));

    Graph<Point>* g = new Grid(gridWidth,gridHeight);
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