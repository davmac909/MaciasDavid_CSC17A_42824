/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: PC
 *
 * Created on May 25, 2016, 7:38 PM
 */
using namespace std;
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    private:
        string name, dpmnt, pstn;
        int idNmbr;
    public:
        Employee();
        void setInfo(string, string, string, int);
        void getInfo() const;
};

#endif /* EMPLOYEE_H */

