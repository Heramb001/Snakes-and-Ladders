#include "snake.h"

#include<iostream>
using namespace std;

snake::snake()
{
    // Constructor
    startPoint = 0;
    endPoint = 0;
}
snake::~snake()
{
    //dtor
}

int snake::getstartPoint(){
    return startPoint;
}
int snake::getendPoint(){
    return endPoint;
}

void snake::setstartPoint(int startpoint){
    startPoint=startpoint;
}
void snake::setendPoint(int endpoint){
    endPoint=endpoint;
}
