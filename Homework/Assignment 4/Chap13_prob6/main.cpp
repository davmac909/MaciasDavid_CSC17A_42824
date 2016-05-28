//System Libraries
#include <iostream>
#include <iomanip>
#include "Inventory.h"
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
void dspInfo(Inventory);

//Execution Begins Here
int main(int argc, char** argv){
    //Declare and initialize Inventory items
    Inventory item1;
    Inventory item2(2, 0.50, 5);
    //Display item Info
    cout <<"Item info just with default constructor:" <<endl;
    dspInfo(item1);
    //set item members using mutator functions
    item1.setItmNum(1);
    item1.setQty(3);
    item1.setCost(2.50);
    item1.setTotCst();
    //Display item info and item2 info
    cout <<"Item info with mutator functions used: " <<endl;
    dspInfo(item1);
    cout <<"Item info using 2nd constructor: " <<endl;
    dspInfo(item2);
    //exit stage right
    return 0;
}

void dspInfo(Inventory i){
    cout <<setw(20) <<left <<"Item Number: " <<i.getItmNum() <<endl;
    cout <<setw(20) <<left <<"Quantity: " <<i.getQty() <<endl;
    cout <<fixed <<showpoint <<setprecision(2);
    cout <<setw(20) <<left <<"Cost: " <<i.getCost() <<endl;
    cout <<setw(20) <<left <<"Total Cost: " <<i.getTotCst() <<endl;
    cout <<endl;
}