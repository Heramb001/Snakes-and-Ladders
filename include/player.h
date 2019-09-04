#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
using namespace std;


class player
{
    public:
        player();
        // Player Structure with its constructor.
        bool isWinner();

        // getters and setters
        string getpName();
        int getpScore();
        int getpPosition();

        void setpName(string playerName);
        void setpScore(int playerScore);
        void setpPosition(int playerPosition);

    protected:

    private:
        string pName;
        int pScore;
        int pPosition;
};

#endif // PLAYER_H
