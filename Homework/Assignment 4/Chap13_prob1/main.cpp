//System Libraries
#include <iostream>
#include "Date.h"
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Declare and initialize variables
    short day, month, year; //day, month, and year to converted
    //Get month
    do{
        cout <<"Enter the number of the Month [1-12]" <<endl;
        cin >>month;
    }while(month < 1 || month > 12);
    //Get day of month
    do{
        cout <<"Enter the day of the month [1-31]" <<endl;
        cin >>day;
    }while(day < 1 || day > 31);
    //Get year
    cout <<"Enter the year" <<endl;
    cin >>year;
    cout <<endl;
    //Map inputs
    Date date(month, day, year);
    //Output dates
    date.prtDate();
    //Exit Stage right
    return 0;
}
