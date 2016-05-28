/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int m, int d, int y){
    day = d;
    month = m;
    year = y;
    const short SIZE = 12;
    string arr[SIZE] = {"January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"};
    
    mnth = new string[SIZE];
    for(int i = 0; i < SIZE; i++){
        mnth[i] = arr[i];
    }
    
}

void Date::prtDate(){
    cout <<month <<"/" <<day <<"/" <<year <<endl;
    cout <<mnth[month-1] <<" " <<day <<", " <<year <<endl;
    cout <<day <<" " <<mnth[month-1] <<" " <<year <<endl;
}

Date::~Date(){
    delete []mnth;
}