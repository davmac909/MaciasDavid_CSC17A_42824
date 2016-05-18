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
const signed short ROW = 15;
const signed short COL = 15;

struct Grid{
    char grid[ROW][COL];
};
struct Location{
    short yLoc, xLoc;
};
struct Ship{
    signed short shipX, shipY, shipL, shipLtemp, ortn;
    Location *crdnts;
};
struct Player{
    
    Grid *grid;
    Ship *ship;
    char intls[NSIZE];
    short time, inCol, inRow, totHit, totMiss, 
    nbombs, nGrids, nShips, shipG, dispG;
    bool bomb, orgn, strt;
    float ratio;
    Player(){
        totHit = 0;
        totMiss = 0;
        nbombs = 5;
        nShips = 5;
        bomb = false;
        orgn = false;
        strt = false;
    }
    
};



#endif /* PLAYER_H */

