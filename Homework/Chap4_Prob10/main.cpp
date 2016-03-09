//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
void getDate(short &, short &);
void proDate(short, short, short &);
void dspRslt(short, short, short);

//Execution Begins Here
int main(int argc, short** argv) {
    //Declare and initialize variables
    short month, year, days;
    
    //Input Data
    getDate(month, year);
    
    //Calculate or map inputs to outputs
    proDate(month, year, days);
    
    //Output the results
    dspRslt(month, year, days);
    
    //Exit stage right
    return 0;
}

void getDate(short &mnth, short &yr){
    //Get the Month [1-12]
    while(mnth < 1 || mnth > 12){
        cout <<"Enter the month." <<endl;
        cin >>mnth;
    }
    //Get the Year
    cout <<"Enter the Year." <<endl;
    cin >>yr;
}

void proDate(short mnth, short yr, short &day){
    if(mnth == 2){
        if(yr%100 == 0 && yr%400 == 0){
            day = 29;
        }else if(yr%4 == 0){
            day = 29;
        }else{
            day = 28;
        }
    }else{
        if(mnth < 8){
            if(mnth%2 == 0){
                day = 30;
            }else{
                day = 31;
            }
        }else{
            if(mnth%2 == 0){
                day = 31;
            }else{
                day = 30;
            }
        }
    }
}

void dspRslt(short mnth, short yr, short day){
    cout <<"The " <<mnth 
                  <<(mnth == 1?"st":          
                     mnth == 2?"nd":
                     mnth == 3?"rd":"th") <<" month" <<endl;
    cout <<"In the year " <<yr <<endl;
    cout <<"Has " <<day <<" days." <<endl;
}