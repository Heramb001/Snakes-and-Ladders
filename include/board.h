#ifndef BOARD_H
#define BOARD_H

#include "snake.h"
#include "ladder.h"

#include<iostream>
using namespace std;


// board class with snakes and ladders
class board
{
    public:
        board();
        virtual ~board();
        snake *snakes;
        ladder *ladders;
        void createSnakes();
        void createLadders();
        void positionSnakes();
        void positionLadders();


        void displayPositionsSL();
        void levelCheckUpdateBoard(bool levelUpdated); // update snakes and ladders;

        int getSnakeTail(int position);
        int getLadderTop(int position);

        bool isSnake(int position);
        bool isLadder(int position);
        string checkPlayerPosition(int &position);

        void digitalBoard(int p1Position, int p2Position, int p1Char, int p2Char); // display player positions graphically.;
        void digitalDice(int dicevalue); // display dice in graphic way;

        void set_num_snakes(int number);
        void set_num_ladders(int number);

        int get_num_snakes();
        int get_num_ladders();

    protected:

    private:

        int num_snakes;
        int num_ladders;

        bool inLadders_Snakes(int &first, int &last);
        void displayIntInChar(int *arr, int sizeofarr, bool newLineRequired);
};

#endif // BOARD_H
