#include <iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
//#include "board.h"
#include "Game.h"

using namespace std;
static const int MAX_SCORE = 100;
// Initialize levels
static bool L1 = false;
static bool L2 = false;
static bool L3 = false;
static bool L4 = false;
static bool L5 = false;

void displayLevels(); // displays Level status on the command line
void continueGame(); // takes input from the user keyboard to continue with the game.

int main()
{
    // Initialize game class as gameplay
    // initialize board class as gameboard -- updated as it is also implemented in game class
    game gameplay;
    //board gameboard;

    //Set  number of players to 2
    int numPlayers = 2;

    // set a gamestate flag to check whether the game is finished or not
    bool gameState = false;

    // string that has the winner name
    string winnerName = "";

    /* Build Board */
    /*// --- OLD CODE
    gameboard.createSnakes(); // creating the snakes
    gameboard.createLadders(); // creating ladders
    gameboard.positionSnakes(); // positioning snakes on board and display on screen
    cout<<endl;
    gameboard.positionLadders(); // positioning snakes on board and display on screen
    */
    gameplay.B.createSnakes(); // creating the snakes
    gameplay.B.createLadders(); // creating ladders
    gameplay.B.positionSnakes(); // positioning snakes on board and display on screen
    cout<<endl;
    gameplay.B.positionLadders(); // positioning snakes on board and display on screen
    /* Board building complete */
    cout << endl << "This is a 2 player game please enter the details of the players : " << endl;
    // create players
    gameplay.createPlayers(numPlayers);
    //get Player Names from the user
    gameplay.getPlayerDetails(numPlayers);
    // play the game until gameState flag is not true
    while(!gameState){
        // For Loop To iterate over the players one at a time
        for(int i=0;i<numPlayers;i++){
            system("CLS");
            // Display Updated player Scores
            //cout <<"Player "<<i+1<<" : "<<gameplay.players[i].pName<<" Turn -> "<<endl;
            cout <<"Player "<<i+1<<" : "<<gameplay.players[i].getpName()<<" Turn -> "<<endl;

            cout << "Please press Enter to roll the dice : "<<endl;
            getch();

            // Display Digital Dice;
            gameplay.displayDice();

            // roll the dice and updating the player scores.
            gameplay.setPlayerScores(i);

            // Display Levels
            displayLevels();
            //Display Snakes and ladders
            //gameboard.displayPositionsSL();
            gameplay.B.displayPositionsSL();
            //Display Digital Board;
            gameplay.displayBoard();
            // Display Player Scores
            gameplay.displayPlayerScores(numPlayers);
            //Press Enter To Continue
            getch();



            // check if the player landed on a Snake, if yes throw him to the end point of the snake, else continue.
            //if(gameboard.isSnake(gameplay.players[i].pPosition)){
            //if(gameboard.isSnake(gameplay.players[i].getpPosition())){
            if(gameplay.B.isSnake(gameplay.players[i].getpPosition())){
                cout<<"OOPS !!! there is a snake in this position."<<endl;
                cout<<"-------------->>>>>>> thrown to tail of the snake."<<endl;
                /* //-- OLD CODE
                gameplay.players[i].pPosition = gameboard.getSnakeTail(gameplay.players[i].pPosition);
                gameplay.players[i].pScore = gameboard.getSnakeTail(gameplay.players[i].pScore);
                cout<<"Player : "<<gameplay.players[i].pName<<" Score : "<<gameplay.players[i].pScore<<" Position : "<<gameplay.players[i].pPosition<<endl;
                continueGame();
                // -- Removed so as to implement single destructor
                gameplay.players[i].setpPosition(gameboard.getSnakeTail(gameplay.players[i].getpPosition()));
                gameplay.players[i].setpScore(gameboard.getSnakeTail(gameplay.players[i].getpScore()));
                */
                gameplay.players[i].setpPosition(gameplay.B.getSnakeTail(gameplay.players[i].getpPosition()));
                gameplay.players[i].setpScore(gameplay.B.getSnakeTail(gameplay.players[i].getpScore()));

                cout<<"Player : "<<gameplay.players[i].getpName()<<" Score : "<<gameplay.players[i].getpScore()<<" Position : "<<gameplay.players[i].getpPosition()<<endl;
                continueGame();
            }
            // check if the player landed on a Ladder, if yes then climb the ladder i.e. update the position of the player to ladder starting position.
            //else if(gameboard.isLadder(gameplay.players[i].pPosition)){
            //else if(gameboard.isLadder(gameplay.players[i].getpPosition())){
            else if(gameplay.B.isLadder(gameplay.players[i].getpPosition())){
                cout<<"Cool. there is a ladder in this position."<<endl;
                cout<<"climbed the ladder ------------->>>>>>>"<<endl;
                /* //-- OLD CODE
                gameplay.players[i].pPosition = gameboard.getLadderTop(gameplay.players[i].pPosition);
                gameplay.players[i].pScore = gameboard.getLadderTop(gameplay.players[i].pScore);
                cout<<"Player : "<<gameplay.players[i].pName<<" Score : "<<gameplay.players[i].pScore<<" Position : "<<gameplay.players[i].pPosition<<endl;
                continueGame();
                //--- Removed so as to implement single destructor
                gameplay.players[i].setpPosition(gameboard.getLadderTop(gameplay.players[i].getpPosition()));
                gameplay.players[i].setpScore(gameboard.getLadderTop(gameplay.players[i].getpScore()));
                */
                gameplay.players[i].setpPosition(gameplay.B.getLadderTop(gameplay.players[i].getpPosition()));
                gameplay.players[i].setpScore(gameplay.B.getLadderTop(gameplay.players[i].getpScore()));

                cout<<"Player : "<<gameplay.players[i].getpName()<<" Score : "<<gameplay.players[i].getpScore()<<" Position : "<<gameplay.players[i].getpPosition()<<endl;
                continueGame();
                }
            //check for levels;
            //if(gameplay.players[i].pPosition > 20 && gameplay.players[i].pPosition < 41){
            if(gameplay.players[i].getpPosition() > 20 && gameplay.players[i].getpPosition() < 41){
                if(!L1){
                    L1=true;
                    //gameboard.levelCheckUpdateBoard(L1);
                    gameplay.B.levelCheckUpdateBoard(L1);
                    continueGame();
                    }
            //}else if(gameplay.players[i].pPosition > 40 && gameplay.players[i].pPosition < 61){
            }else if(gameplay.players[i].getpPosition() > 40 && gameplay.players[i].getpPosition() < 61){
                if(!L2){
                    L2=true;
                    //gameboard.levelCheckUpdateBoard(L2);
                    gameplay.B.levelCheckUpdateBoard(L2);
                    continueGame();
                    }
            //}else if(gameplay.players[i].pPosition > 60 && gameplay.players[i].pPosition < 81){
            }else if(gameplay.players[i].getpPosition() > 60 && gameplay.players[i].getpPosition() < 81){
                if(!L3){
                    L3=true;
                    //gameboard.levelCheckUpdateBoard(L3);
                    gameplay.B.levelCheckUpdateBoard(L3);
                    continueGame();
                    }
            //}else if(gameplay.players[i].pPosition > 80 && gameplay.players[i].pPosition < 100){
            }else if(gameplay.players[i].getpPosition() > 80 && gameplay.players[i].getpPosition() < 100){
                if(!L4){
                    L4=true;
                    //gameboard.levelCheckUpdateBoard(L4);
                    gameplay.B.levelCheckUpdateBoard(L4);
                    continueGame();
                    }
            }
            // check if we get a winner if yes break the loop, else continue with the loop.
            if(gameplay.players[i].isWinner()){
                    //winnerName = gameplay.players[i].pName;
                    winnerName = gameplay.players[i].getpName();
                    gameState=true;
                    break;
            }
        }
    }
    // Displaying the winner
    system("CLS");

    cout<<endl;
    cout<<"<------------ Game Finished !!! ------------>"<<endl;
    cout<<"  Winner is : "<<winnerName<<endl;
    return 0;
}

// takes input from the user keyboard to continue with the game.
void continueGame(){
    cout << "Please press Enter to continue"<<endl;
    getch();
}

// displays Level status on the command line
void displayLevels(){
    cout<<"<-- Levels Status -->"<<endl;
    if(L1){cout<<"Level 1 : Crossed"<<endl;}else{cout<<"Level 1 : Not Crossed"<<endl;}
    if(L2){cout<<"Level 2 : Crossed"<<endl;}else{cout<<"Level 2 : Not Crossed"<<endl;}
    if(L3){cout<<"Level 3 : Crossed"<<endl;}else{cout<<"Level 3 : Not Crossed"<<endl;}
    if(L4){cout<<"Level 4 : Crossed"<<endl;}else{cout<<"Level 4 : Not Crossed"<<endl;}
    if(L5){cout<<"Level 5 : Crossed"<<endl;}else{cout<<"Level 5 : Not Crossed"<<endl;}
    cout<<"<------------------->"<<endl;
}
