/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: PC
 *
 * Created on April 30, 2016, 5:19 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
using namespace std;
const short NSIZE = 3;

struct Player{
    
    char intls[NSIZE];
    short time, inCol, inRow, totHit, totMiss, nbombs;
    bool bomb;
    float ratio;
    Player(){
        totHit = 0;
        totMiss = 0;
        nbombs = 5;
        bomb = false;
    }
    
};



#endif /* PLAYER_H */

