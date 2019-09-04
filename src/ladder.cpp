#include "ladder.h"

#include<iostream>
using namespace std;

ladder::ladder()
{
    //ctor
    startPoint = 0;
    endPoint = 0;
}

ladder::~ladder()
{
    //dtor
}

int ladder::getstartPoint(){
    return startPoint;
}
int ladder::getendPoint(){
    return endPoint;
}

void ladder::setstartPoint(int startpoint){
    startPoint=startpoint;
}
void ladder::setendPoint(int endpoint){
    endPoint=endpoint;
}
