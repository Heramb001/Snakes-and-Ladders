#include "player.h"

#include<iostream>
using namespace std;

player :: player(){
    pName = "";
    pScore = 0;
    pPosition = 0;
}

bool player :: isWinner(){
    bool state = false;
    if(pScore >= 100){
        state = true;
    }
    return state;
}

// getters and setters
string player :: getpName(){
    return pName;
}
int player :: getpScore(){
    return pScore;
}
int player :: getpPosition(){
    return pPosition;
}

void player :: setpName(string playerName){
    pName = playerName;
}
void player :: setpScore(int playerScore){
    pScore = playerScore;
}
void player :: setpPosition(int playerPosition){
    pPosition = playerPosition;
}
