#ifndef GAME_H
#define GAME_H

#include "player.h"
//#include "dice.h"
#include "board.h"

#include<iostream>
using namespace std;


// ---* Class Game and its member functions *---
class game
{
    public:
        game();
        virtual ~game();
        player *players;
        board B;
        //dice dice;
        void createPlayers(int &numPlayers);
        void getPlayerDetails(int &numPlayers);
        void setPlayerScores(int &numPlayers);
        //string getWinner(int &numPlayers);


        void displayPlayerScores(int &numPlayers);
        void displayBoard();
        void displayDice();
        void displaySnakesLadders();

        //Dice Function // updates diceVal variable
        int diceroll();
        void set_num_Players(int number);
        void set_diceVal(int value);

        int get_num_Players();
        int get_diceVal();

    protected:

    private:
        int num_Players;
        int diceVal;
};

#endif // GAME_H
