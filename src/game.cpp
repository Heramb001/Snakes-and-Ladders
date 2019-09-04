#include "Game.h"

#include<iomanip>

/*
 * The Game Class has all the other classes as its members and us used in the gameplay.
 * Below are the member functions of the game class
 * createPlayers() - Creates the Players from Players class.
 * getPlayerDetails() - get player details from the users.
 * setPlayerScores() - Set Player Scores.
 * getWinner() - Check if we have a winner.
 * displayPlayerScores() - Displays Players Scores on screen
 * displaySnakesLadders() - Displays Snakes and Ladders on screen.
 * displayBoard() - Display Graphical board.
 * displayDice() - Display Graphical Dice.
*/

game::game()
{
    //ctor
    num_Players = 0;
    diceVal = 0;
}

game::~game()
{
    //dtor
    delete []players;
}
void game::set_num_Players(int number){
    num_Players = number;
}

void game::set_diceVal(int value){
    diceVal = value;
}

int game::get_num_Players(){
    return num_Players;
}

int game::get_diceVal(){
    return diceVal;
}


void game :: createPlayers(int &numPlayers){
    num_Players = numPlayers;
    players = new player[numPlayers];
}


void game :: getPlayerDetails(int &numPlayers){
    string tempName = "";
    for(int i=0;i<numPlayers;i++)
        {
            cout<<"-> Please enter the Player "<<i+1<<" details : "<<endl;
            /* // ----Old Code
            cin>>players[i].pName;
            players[i].pPosition=0;
            players[i].pScore=0;
            */
            cin>>tempName;
            players[i].setpName(tempName);
            players[i].setpPosition(0);
            players[i].setpScore(0);
        }
    }

void game :: setPlayerScores(int &PlayerIndex){
    //int d_value = 0;
    //d_value = dice.roll();
    //diceVal = d_value;
    /* //---- OLD code
    players[PlayerIndex].pScore = players[PlayerIndex].pScore+diceVal;
    players[PlayerIndex].pPosition = players[PlayerIndex].pPosition+diceVal;
    cout<<"Player "<<players[PlayerIndex].pName<<" updated score : "<<players[PlayerIndex].pScore<<" updated Position : "<<players[PlayerIndex].pPosition<<endl;
    */

    players[PlayerIndex].setpScore(players[PlayerIndex].getpScore()+diceVal);
    players[PlayerIndex].setpPosition(players[PlayerIndex].getpPosition()+diceVal);
    cout<<"Player "<<players[PlayerIndex].getpName()<<" updated score : "<<players[PlayerIndex].getpScore()<<" updated Position : "<<players[PlayerIndex].getpPosition()<<endl;

    }
/* // -- Redundant function
string game :: getWinner(int &numPlayers){
    string winner = "";
    for(int i=0;i<numPlayers;i++){
    }
    return winner;
}
*/
// end of Class Game and its member functions

void game :: displayPlayerScores(int &numPlayers){

    cout<<" Player "<<setw(15)<<" Position "<<endl;
    for(int i=0;i<numPlayers;i++){
        //cout<<players[i].pName<<setw(15)<<players[i].pPosition<<endl;
        cout<<players[i].getpName()<<setw(15)<<players[i].getpPosition()<<endl;
    }
}

void game :: displaySnakesLadders(){
    int SN = B.get_num_snakes();
    int LD = B.get_num_ladders();
    for(int m=0;m<SN;m++){
            cout<<"IN Loop : "<<endl;
            cout<<"Snake "<<m;
            //cout<<" START : "<<B.snakes[m].startPoint<<" , END : "<<B.snakes[m].endPoint<<endl;
            cout<<" START : "<<B.snakes[m].getstartPoint()<<" , END : "<<B.snakes[m].getendPoint()<<endl;
     }
     cout<<endl;
     for(int i=0;i<LD;i++){
            //cout<<"Ladder "<<i<<" START : "<<B.ladders[i].startPoint<<" , END : "<<B.ladders[i].endPoint<<endl;
            cout<<"Ladder "<<i<<" START : "<<B.ladders[i].getstartPoint()<<" , END : "<<B.ladders[i].getendPoint()<<endl;
      }
}


void game :: displayBoard(){
    cout<<endl;
    //B.displayPositionsSL();
    /* //-- OLD Code
    cout<<"-> Player P1 "<<players[0].pName<<" : "<<char(178)<<endl;
    cout<<"-> Player P2 "<<players[1].pName<<" : "<<char(176)<<endl;
    cout<<"<---------- Board with Player Positions. --------->"<<endl;
    cout<<endl;
    int p1 = players[0].pPosition;
    int p2 = players[1].pPosition;
    B.digitalBoard(p1,p2,178,176);
    cout<<endl;
    cout<<"<------------------------------------------------->"<<endl;
    */
    cout<<"-> Player P1 "<<players[0].getpName()<<" : "<<char(178)<<endl;
    cout<<"-> Player P2 "<<players[1].getpName()<<" : "<<char(176)<<endl;
    cout<<"<---------- Board with Player Positions. --------->"<<endl;
    cout<<endl;
    int p1 = players[0].getpPosition();
    int p2 = players[1].getpPosition();
    B.digitalBoard(p1,p2,178,176);
    cout<<endl;
    cout<<"<------------------------------------------------->"<<endl;
}

void game :: displayDice(){
    cout<<endl;
    //diceVal = dice.roll();
    diceVal = diceroll();
    B.digitalDice(diceVal);
    cout<<endl;
}


int game :: diceroll(){
        int val = 0;
        srand(time(NULL));
        val = 1 + rand() % (7-1);  //assigns a random number between 1-6 to variable
        cout<<"-> dice rolled with value : "<<val<<endl;
        //score=score+val;
        return val;
}
