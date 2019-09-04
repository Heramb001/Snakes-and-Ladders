#ifndef LADDER_H
#define LADDER_H

#include<iostream>
using namespace std;

class ladder
{
    public:
        ladder();
        ~ladder();

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

#endif // LADDER_H
