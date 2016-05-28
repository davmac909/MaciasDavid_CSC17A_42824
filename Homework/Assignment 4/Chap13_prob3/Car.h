/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.h
 * Author: PC
 *
 * Created on May 25, 2016, 9:25 PM
 */

#include <iostream>
#ifndef CAR_H
#define CAR_H
using namespace std;

class Car {
private:
    string make;
    int yrMdl, speed;
public:
    Car(int, string);
    int getYrMdl();
    string getMake();
    int getSpd();
    void accl();
    void brake();
};

#endif /* CAR_H */

