/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Company.h
 * Author: PC
 *
 * Created on April 26, 2016, 11:34 PM
 */

#ifndef COMPANY_H
#define COMPANY_H
const short NAMSIZE = 30;

struct Company{
    
    char dvsName[NAMSIZE];
    short qtr;
    float qtrSale;
};


#endif /* COMPANY_H */

