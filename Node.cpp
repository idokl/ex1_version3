//
// Created by ido on 24/11/16.
//

#include "Node.h"
template <class T>
Node<T>::Node(T value) {
    this->value = value;
}

template <class T>
bool Node<T>::operator==(Node<T> &other) {
    return (this->value == other.value);
}

template <class T>
bool Node<T>::operator<(Node<T> &other) {
    return (this->value < other.value);
}

template <class T>
T Node<T>::getValue() {
    return this->value;
}
