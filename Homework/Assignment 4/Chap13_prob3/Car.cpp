/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Car.h"
using namespace std;

Car::Car(int y, string m){
    yrMdl = y;
    make = m;
    speed = 0;
}

int Car::getYrMdl(){
    return yrMdl;
}

string Car::getMake(){
    return make;
}

int Car::getSpd(){
    return speed;
}

void Car::accl(){
    speed += 5;
}

void Car::brake(){
    speed -= 5;
}