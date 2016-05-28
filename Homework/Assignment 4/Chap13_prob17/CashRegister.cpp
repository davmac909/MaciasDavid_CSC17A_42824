/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "CashRegister.h"
using namespace std;

CashRegister::CashRegister(){
    adjCost = 0;
    subTot = 0;
    purTot = 0;
    tax = 0;
    sldItmNum = 0;
    size = 10;
    item = new Inventory[size];
    for(int i = 0; i < size; i++){
        item[i].setItmNum(i+1);
        item[i].setQty(rand()%10+10);
        item[i].setCost(rand()%9+1);
        item[i].setTotCst();
    }
}

void CashRegister::getItemInfo(int i) const{
    cout <<setw(10) <<left <<item[i].getItmNum();
    cout <<setw(10) <<left <<item[i].getQty();
    cout <<fixed <<showpoint <<setprecision(2);
    cout <<setw(10) <<left <<item[i].getCost();
    cout <<setw(10) <<left <<item[i].getTotCst();
    cout <<endl;
    
}
float CashRegister::getCst(int i) const{
   return item[i].getCost();
}

void CashRegister::setAdjCost(int i){
    float a = item[i].getCost()*0.3f;
    adjCost = item[i].getCost()+a;
}

void CashRegister::setSubTot(){
    subTot = adjCost*sldQty;
}
void CashRegister::setPurTot(){
    tax = subTot*0.06f;
    purTot = subTot+tax;
}
float CashRegister::getAdjCost() const{
    return adjCost;
}
    
float CashRegister::getSubTot() const{
    return subTot;
}
float CashRegister::getPurTot() const{
    return purTot;
}
float CashRegister::getTax() const{
    return tax;
}
short CashRegister::getSize() const{
    return size;
}
short CashRegister::getItmQty(short i) const{
    return item[i].getQty();
}

void CashRegister::setItmNum(int i){
    sldItmNum = i;
}
short CashRegister::getItmNum() const{
    return sldItmNum;
}
void CashRegister::setSldQty(int i){
    sldQty = i;
}
short CashRegister::getSldQty() const{
    return sldQty;
}