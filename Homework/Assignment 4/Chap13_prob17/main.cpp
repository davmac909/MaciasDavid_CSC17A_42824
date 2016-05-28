//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Inventory.h"
#include "CashRegister.h"
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
void dspItms(CashRegister);
void calcPur(CashRegister &);
void dspRcpt(CashRegister);

//Execution Begins Here
int main(int argc, char** argv){
    //set random time seed
    srand(static_cast<int>(time(0)));
    //Declare and initialize CashRegister class
    CashRegister store;
    //Get item and quantity
    calcPur(store);
    //Display Purchase Receipt
    dspRcpt(store);
    //exit stage right
    return 0;
}

void dspItms(CashRegister c){
    //Display item info and item2 info
    cout <<setw(10) <<left <<"Item #" <<setw(10) <<left <<"Quantity" 
         <<setw(10) <<left <<"Cost" <<setw(10) <<left <<"Total Cost" <<endl;
    for(int i = 0; i < c.getSize(); i++){
        c.getItemInfo(i);
    }
}

void calcPur(CashRegister &c){
    //Output items list
    int a, b;
    dspItms(c);
    //Get Inputs
    do{
        cout <<endl;
        cout <<"Enter the Item Number being purchased ";
        cout <<"[1-" <<c.getSize() <<"]" <<endl;
        cin >>a;
    }while(a < 1 || a > c.getSize());
    a -= 1;
    do{
        cout <<endl;
        cout <<"Enter the Quantity of Item Number " <<a+1 <<" being Purchased ";
        cout <<"[1-" <<c.getItmQty(a) <<"]" <<endl;
        cin >>b;
    }while(b < 1 || b > c.getItmQty(a));
    //calculate purchase total
    c.setItmNum(a);
    c.setSldQty(b);
    c.setAdjCost(c.getItmNum());
    c.setSubTot();
    c.setPurTot();
}

void dspRcpt(CashRegister c){
    cout <<endl;
    cout <<"---------------------------------" <<endl;
    cout <<"--------Purchase Receipt---------" <<endl;
    cout <<"---------------------------------" <<endl;
    cout <<"Item:" <<endl;
    cout <<c.getItmNum() <<endl;
    cout <<setw(5) <<right <<"(" <<c.getSldQty() <<" @ " <<c.getAdjCost() <<")";
    cout <<setw(18) <<right <<c.getSubTot() <<endl <<endl;
    cout <<setw(27) <<right <<"Subtotal $" <<setw(6) <<right 
            <<c.getSubTot() <<endl;
    cout <<setw(27) <<right <<"Tax (6%) $" <<setw(6) <<right 
            <<c.getTax() <<endl;
    cout <<setw(27) <<right <<"Purchase Total $" <<setw(6) <<right 
            <<c.getPurTot() <<endl;
}