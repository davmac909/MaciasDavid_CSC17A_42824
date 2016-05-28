/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: PC
 *
 * Created on May 25, 2016, 6:14 PM
 */

#ifndef DATE_H
#define DATE_H
using namespace std;

class Date {
private:
    int day, month, year; //
    string *mnth;
public:
    Date(int, int, int);
    void prtDate();
    ~Date();
};

#endif /* DATE_H */

