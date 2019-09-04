#include "board.h"

#include<iostream>
#include<conio.h>
using namespace std;

/*
 * we have 5 snakes and 5 ladders that randomly get arranged, below are the member functions that are implemented in board class
 * createSnakes() - Creates the snakes from the snake class.
 * createLadders() - Creates the Ladders from the ladder class.
 * positionSnakes() - Positions the snakes on board
 * positionLadders() - Positions the ladders on board
 * displayPositionsSL() - Displays Snakes and Ladders Positions on screen
 * isSnake() - checks for a given position there is a snake or not.
 * isLadder() - checks for a given position there is a Ladder or not.
 * getSnakeTail() - go to the tail position of snake from head position.
 * getLadderTop() - go to the Top position of ladder from bottom position.
 * levelCheckUpdateBoard() - check for the level and update the snakes and ladders positions.
 * digitalBoard() - Displays GameBoard in a graphical way.
 * digitalDice() - Displays Dice in a graphical way.

 Private :
 * displayIntInChar() - Displays Int value in character(used in displaying ASCII characters using their integer form)
 * inLadders_Snakes() - this function validates whether the generated snake or ladder is already present on the board or not.
*/
board::board()
{
    //ctor
    num_snakes = 5;
    num_ladders = 5;
}

board::~board()
{
    //dtor
    delete []snakes;
    delete []ladders;
}

void board::set_num_snakes(int number){
    num_snakes = number;
}

void board::set_num_ladders(int number){
    num_ladders = number;
}

int board::get_num_snakes(){
    return num_snakes;
}
int board::get_num_ladders(){
    return num_ladders;
}


void board :: createSnakes(){
    snakes = new snake[num_snakes];
}

void board :: createLadders(){
    ladders = new ladder[num_ladders];
}

void board :: positionSnakes(){
    int s_head = 0,s_tail = 0;
    for(int i=0;i<num_snakes;i++){
        s_start : s_head = rand()%100 + 1; // generates a random number between 1 to 100 for Snake Head
        s_end : s_tail = rand()%50 + 1; // generates a random number between 1 to 50 for Snake Tail
        if (s_tail > s_head) // Check if tail is greater than tail or vice versa
            goto s_end;      // if yes then go back to generating tail, as tail should not be greater that head
        if (inLadders_Snakes(s_head,s_tail)){ // check if we have a similar snake positions earlier in the snakes array or ladders array as for one position we have either a snake or a ladder
            goto s_start;    // if we have any repeating position then start generating the positions again.
        }
        /* Old Code */
        /*
        snakes[i].startPoint = s_head; // assign Start position of Snake
        snakes[i].endPoint   = s_tail; // assign End position of Snake
        */
        /* New Code */
        snakes[i].setstartPoint(s_head); // assign Start position of Snake
        snakes[i].setendPoint(s_tail); // assign End position of Snake

        //cout<<"Snake "<<i+1<<" START : "<<snakes[i].startPoint<<" , END : "<<snakes[i].endPoint<<endl;
    }
}

void board :: positionLadders(){
    int l_bottom = 0,l_top = 0;
    for(int i=0;i<num_ladders;i++){
        l_start : l_bottom = rand()%50 + 1; // generates a random number between 1 to 50 for ladder Bottom
        l_end : l_top = rand()%100 + 1;     // generates a random number between 1 to 100 for ladder Top
        if (l_top < l_bottom)               // Check if top is less than tail or vice versa
            goto l_end;                     // if yes then go back to generating top position for ladder, as Top should not be less that bottom.
        if (inLadders_Snakes(l_bottom,l_top)){ // check if we have a similar Ladder positions earlier in the snakes array or ladders array as for one position we have either a snake or a ladder
            goto l_start;                   // if we have any repeating position then start generating the positions again.
        }
        /* Old Code */
        /* ladders[i].startPoint = l_bottom;   // assign Start position of Ladder
           ladders[i].endPoint   = l_top;      // assign End position of Ladder
        */

        /*New Code*/
        ladders[i].setstartPoint(l_bottom);   // assign Start position of Ladder
        ladders[i].setendPoint(l_top);      // assign End position of Ladder
        //cout<<"Ladder "<<i+1<<" START : "<<ladders[i].startPoint<<" , END : "<<ladders[i].endPoint<<endl;
    }
}

bool board :: inLadders_Snakes(int &first, int &last){
    for(int i=0;i<num_ladders;i++){
        //if(ladders[i].startPoint == first || ladders[i].endPoint == last || snakes[i].startPoint == first || snakes[i].endPoint == last)
        if(ladders[i].getstartPoint() == first || ladders[i].getendPoint() == last || snakes[i].getstartPoint() == first || snakes[i].getendPoint() == last)
            return true;
    }
    return false;
}

bool board :: isSnake(int position){
    for(int i=0;i<num_snakes;i++){
        if(position == snakes[i].getstartPoint())
            return true;
    }
    return false;
}

bool board :: isLadder(int position){
    for(int i=0;i<num_ladders;i++){
        if(position == ladders[i].getstartPoint())
            return true;
    }
    return false;
}

int board :: getSnakeTail(int position){
    int tail = 0;
    for(int i=0;i<num_snakes;i++){
        if(position == snakes[i].getstartPoint())
        //if(position == snakes[i].startPoint)
            //tail = snakes[i].endPoint;
            tail = snakes[i].getendPoint();
        }
    return tail;
}

int board :: getLadderTop(int position){
    int tail = 0;
    for(int i=0;i<num_ladders;i++){
        if(position == ladders[i].getstartPoint())
        //if(position == ladders[i].startPoint)
            //tail = ladders[i].endPoint;
            tail = ladders[i].getendPoint();
        }
    return tail;
}


void board :: displayPositionsSL(){
    cout<<"<-------- Display Snakes And Ladders Position --------->"<<endl;
     for(int i=0;i<num_snakes;i++){
            //cout<<"Snake "<<i+1<<" START : "<<snakes[i].startPoint<<" , END : "<<snakes[i].endPoint<<endl;
            cout<<"Snake "<<i+1<<" START : "<<snakes[i].getstartPoint()<<" , END : "<<snakes[i].getendPoint()<<endl;
     }
     cout<<endl;
     for(int i=0;i<num_ladders;i++){
            //cout<<"Ladder "<<i+1<<" START : "<<ladders[i].startPoint<<" , END : "<<ladders[i].endPoint<<endl;
            cout<<"Ladder "<<i+1<<" START : "<<ladders[i].getstartPoint()<<" , END : "<<ladders[i].getendPoint()<<endl;
      }
      cout<<"<---------------------------------------------------->"<<endl;
}

void board :: levelCheckUpdateBoard(bool levelUpdated){
    cout<<"<-------- Level Updated, Snakes and Ladders are reset. --------->"<<endl;
    //updating snakes and ladders position;
    positionSnakes(); // updating snakes positions
    positionLadders(); // updating ladders position
}

void board :: displayIntInChar(int *arr, int sizeofarr, bool newLineRequired){
    int aSize = sizeofarr;
    for(int i=0;i<aSize;i++){
        cout<<char(arr[i]);
    }
    if(newLineRequired){
        cout<<endl;
    }
}

/* display player positions graphically.;
*/
void board :: digitalBoard(int p1Position, int p2Position, int p1Char, int p2Char){
    // one top    : 201,205,205,205,205,203
    // one middle : 204,205,205,205,205,206
    // one bottom : 200,205,205,205,205,202
    int topl[] = {201,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,203,205,205,205,205,187};
    int midl[] = {204,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,206,205,205,205,205,185};
    int bottoml[] = {200,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,202,205,205,205,205,188};
    int arr[10][10] = {{100,99,98,97,96,95,94,93,92,91},
                        {81,82,83,84,85,86,87,88,89,90},
                        {80,79,78,77,76,75,74,73,72,71},
                        {61,62,63,64,65,66,67,68,69,70},
                        {60,59,58,57,56,55,54,53,52,51},
                        {41,42,43,44,45,46,47,48,49,50},
                        {40,39,38,37,36,35,34,33,32,31},
                        {21,22,23,24,25,26,27,28,29,30},
                        {20,19,18,17,16,15,14,13,12,11},
                        {1,2,3,4,5,6,7,8,9,10}};

    int x,y;
    // to print top row
    displayIntInChar(topl,51,true);
    for(x=0;x<10;x++){
        for(y=0;y<10;y++){
            if(y==0){
                cout<<char(186);
            }
            if(arr[x][y] < 10){
                /*if(p1Position == p2Position){
                    if(arr[x][y] == p1Position){
                        cout<<char(178)<<char(177)<<arr[x][y]<<char(32); // prints space, P2 Position, position, space
                    }
                }else{*/
                if(arr[x][y] == p1Position){
                    cout<<char(p1Char)<<char(32)<<arr[x][y]<<char(32); // prints space, P2 Position, position, space
                }else if(arr[x][y] == p2Position){
                    cout<<char(32)<<char(p2Char)<<arr[x][y]<<char(32); // prints space, P2 Position, position, space
                }else{
                    cout<<char(32)<<char(32)<<arr[x][y]<<char(32); // prints 2 spaces, position, space
                }
                //}
            }else{
                if(arr[x][y] < 100){
                    /*if(p1Position == p2Position){
                        if(arr[x][y] == p1Position){
                            cout<<char(178)<<arr[x][y]<<char(177); // prints space, P2 Position, position, space
                        }
                    }else{*/
                    if(arr[x][y] == p1Position){
                        cout<<char(p1Char)<<arr[x][y]<<char(32); // prints space, P2 Position, position, space
                    }else if(arr[x][y] == p2Position){
                        cout<<char(32)<<arr[x][y]<<char(p2Char); // prints space, P2 Position, position, space
                    }else{
                        cout<<char(32)<<arr[x][y]<<char(32); // prints space position and space
                    }
                    //}
                }else{
                    cout<<arr[x][y]<<char(32); // prints position and space
                }
            }
            cout<<char(186);
        }
        cout<<endl;
        if(x<9){
            //print middle row
            displayIntInChar(midl,51,true);
        }
    }
    //prints bottom border
    displayIntInChar(bottoml,51,true);
}


/* display dice in graphic way;
*/
void board :: digitalDice(int dicevalue){
    int dicetop[] = {201,205,205,205,205,205,205,187};
    int dicemid1[] = {186,32,32,32,32,32,32,186};
    int dicemid2[] = {186,32,32,32,32,32,32,186};
    int dicemid3[] = {186,32,32,32,32,32,32,186};
    int dicebottom[] = {200,205,205,205,205,205,205,188};
    if(dicevalue == 1){
        dicemid2[3] = 219;
        dicemid2[4] = 219;
    }else if(dicevalue == 2){
        dicemid2[2] = 254;
        dicemid2[5] = 254;
    }else if(dicevalue == 3){
        dicemid1[6] = 254;
        dicemid2[4] = 254;
        dicemid3[2] = 254;
    }else if(dicevalue == 4){
        dicemid1[2] = 254;
        dicemid1[5] = 254;
        dicemid3[2] = 254;
        dicemid3[5] = 254;
    }else if(dicevalue == 5){
        dicemid1[2] = 254;
        dicemid1[6] = 254;
        dicemid2[4] = 254;
        dicemid3[2] = 254;
        dicemid3[6] = 254;
    }else if(dicevalue == 6){
        dicemid1[2] = 254;
        dicemid1[5] = 254;
        dicemid2[2] = 254;
        dicemid2[5] = 254;
        dicemid3[2] = 254;
        dicemid3[5] = 254;
    }
    //displaying dice
    displayIntInChar(dicetop,8,true);
    displayIntInChar(dicemid1,8,true);
    displayIntInChar(dicemid2,8,true);
    displayIntInChar(dicemid3,8,true);
    displayIntInChar(dicebottom,8,true);
    cout<<endl;
}


