/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

Employee::Employee(){
    name = "";
    dpmnt = "";
    pstn = "";
    idNmbr = 0;
}

void Employee::setInfo(string n, string d, string p, int id){
    name = n;
    dpmnt = d;
    pstn = p;
    idNmbr = id;
}

void Employee::getInfo() const{
    cout <<setw(20) <<left <<name  <<setw(20) <<left <<idNmbr <<setw(20) <<left <<dpmnt <<setw(20) <<left <<pstn <<endl;
}