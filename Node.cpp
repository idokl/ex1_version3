#include "Node.h"

using namespace std;

Node::Node(int xCoord, int yCoord): x(xCoord), y(yCoord) {
}

int Node::getX() {
    return x;
}

int Node::getY() {
    return y;
}

bool Node::isAvailable() {
    return true;
}

bool Node::operator==(const Node &p1) const {
    return((x==p1.x)&&(y==p1.y));
}

bool Node::operator<(const Node &p1) const {
    if ((x < p1.x) || ((x == p1.x) && (y < p1.y)))
        return true;
    else
        return false;
}

ostream& operator <<(ostream& os, const Node &point) {
    return os << "(" << point.x << "," << point.y << ")";
}