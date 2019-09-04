#ifndef SNAKE_H
#define SNAKE_H

#include<iostream>
using namespace std;

class snake
{
    public:
        snake();
        ~snake();
        //getters and setters
        int getstartPoint();
        int getendPoint();

        void setstartPoint(int startpoint);
        void setendPoint(int endpoint);
    protected:

    private:
        int startPoint;
        int endPoint;
};

#endif // SNAKE_H
