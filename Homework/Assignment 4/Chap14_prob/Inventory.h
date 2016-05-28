/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Inventory.h
 * Author: PC
 *
 * Created on May 25, 2016, 9:51 PM
 */

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory {
private:
    int itmNum, qty;
    float cost, totCost;
public:
    Inventory();
    Inventory(int, float, int);
    void setItmNum(int);
    void setQty(int);
    void setCost(float);
    void setTotCst();
    int getItmNum() const;
    int getQty() const;
    float getCost() const;
    float getTotCst() const;
    
};


#endif /* INVENTORY_H */

