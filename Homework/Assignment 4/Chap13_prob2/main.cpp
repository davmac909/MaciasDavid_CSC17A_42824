//System Libraries
#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Declare and initialize variables
    const short SIZE = 3;       //size of class object, name array, department array, position array, and ID Number array;
    Employee worker[SIZE];      
    string name[SIZE] = {"Susan Meyers", "Mark Jones", "Joy Rogers"}; //Names of employees
    string dpt[SIZE] = {"Accounting", "IT", "Manufacturing"}; //Departments employees are in
    string pos[SIZE] = {"Vice President", "Programmer", "Engineer"}; //positions of employees
    int idNum[SIZE] = {47899, 39119, 81774}; //ID Numbers of employees
    //Set Information for each employee
    for(int i = 0; i < SIZE; i++){
        worker[i].setInfo(name[i], dpt[i], pos[i], idNum[i]);
    }
    //Output Employee data
    cout <<"--------------------------------------------------------------------" <<endl;
    cout <<setw(20) <<left <<"Name" <<setw(20) <<left <<"ID Number" <<setw(20) 
            <<left <<"Department" <<setw(20) <<left <<"Position" <<endl;
    cout <<"--------------------------------------------------------------------" <<endl;
    for(int i = 0; i < SIZE; i++){
        worker[i].getInfo();
    }
    //exit stage right
    return 0;
}
