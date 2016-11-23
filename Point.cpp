//
// Created by ohad on 23/11/16.
//


#include "Point.h"

bool operator==(const Node &p1) const {

};

Point::Point(int x, int y) : x(x),y(y){

}

void* getValue(){
    return new Point(0,0);
}
