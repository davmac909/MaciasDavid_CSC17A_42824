/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CashRegister.h
 * Author: PC
 *
 * Created on May 25, 2016, 11:36 PM
 */
#include "Inventory.h"
#ifndef CASHREGISTER_H
#define CASHREGISTER_H

class CashRegister {
private:
    Inventory *item;
    float adjCost, subTot, tax, purTot;
    short sldItmNum, sldQty, size;
public:
    CashRegister();
    short getSize() const;
    short getItmQty(short) const;
    void getItemInfo(int) const;
    float getCst(int) const;
    void setAdjCost(int);
    void setSubTot();
    void setPurTot();
    void setTax();
    float getTax() const;
    float getAdjCost() const;
    float getSubTot() const;
    float getPurTot() const;
    void setItmNum(int);
    short getItmNum() const;
    void setSldQty(int);
    short getSldQty() const;
};

#endif /* CASHREGISTER_H */

