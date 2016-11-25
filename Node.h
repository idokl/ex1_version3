/*
 * This class represents position of point in the plane.
 * It maintain the point's coordinates in the x axe and the y axe.
*/

#ifndef EX1_POINT_H
#define EX1_POINT_H

#include <iostream>

using namespace std;

template <class T> class Node;

template <class T>
class Node {
    T value;
public:
    Node(T value);
    //Points comparison according to the x and y coordinates
    virtual bool operator==( Node<T> &other);
    //definition of ordering relation between Points in order to enable
    //data structures (like Map) to maintain them efficiently.
    //(the exact ordering relation, that we defined, doesn't matter)
    virtual bool operator<(const Node<T> &other) const;
    //overloading operator to print this Node (by cout) in the format: (x,y)
    //friend ostream& operator <<(ostream& os, Node &point);
    T getValue();
};

template <class T>
Node<T>::Node(T value) : value(value)
{
    //this->value = value;
}

template <class T>
bool Node<T>::operator==(Node<T> &other) {
    return (this->value == other.value);
}

template <class T>
bool Node<T>::operator<(const Node<T> &other) const {
    return (this->value < other.value);
}

template <class T>
T Node<T>::getValue() {
    return this->value;
}


#endif //EX1_POINT_H
