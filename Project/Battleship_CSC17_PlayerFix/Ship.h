/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Ship.h
 * Author: PC
 *
 * Created on April 30, 2016, 1:25 PM
 */

#ifndef SHIP_H
#define SHIP_H
struct Location{
    short yLoc, xLoc;
};
struct Ship{
    signed short shipX, shipY, shipL, shipLtemp;
    Location *crdnts;
};


#endif /* SHIP_H */

