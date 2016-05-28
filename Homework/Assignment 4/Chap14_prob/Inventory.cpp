/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Inventory.h"

Inventory::Inventory(){
    itmNum = 0;
    qty = 0;
    cost = 0;
    totCost = 0;
}

Inventory::Inventory(int i, float c, int q){
    itmNum = i;
    cost = c;
    qty = q;
    Inventory::setTotCst();
}

void Inventory::setItmNum(int i){
    itmNum = i;
}

void Inventory::setQty(int q){
    qty = q;
}

void Inventory::setCost(float c){
    cost = c;
}

void Inventory::setTotCst(){
    totCost = qty*cost;
}

int Inventory::getItmNum() const{
    return itmNum;
}

int Inventory::getQty() const{
    return qty;
}

float Inventory::getCost() const{
    return cost;
}

float Inventory::getTotCst() const{
    return totCost;
}