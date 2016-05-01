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

struct Player{
    string intls;
    short inCol, inRow, totHit = 0, totMiss = 0, nbombs = 3;
    bool bomb = false;
    float time, ratio;
    
};



#endif /* PLAYER_H */

