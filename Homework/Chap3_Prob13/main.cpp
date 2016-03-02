//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here


int main(int argc, char** argv) {
    //Declare and initialize variables
    float dlls, yen = 0, euro = 0;
    const float YENDLL = 98.93, EURODLL = 0.74;
    
    //Input Data
    cout <<"Input the Number of dollars to be exchanged" <<endl;
    cin >>dlls;
    
    //Calculate or map inputs to outputs
    yen = dlls*YENDLL;
    euro = dlls*EURODLL;
    
    //Output the results
    cout <<setprecision(2) <<showpoint <<fixed <<setw(6) ;
    cout <<dlls <<" Dollars can be exchanged for:" <<endl;
    cout <<yen <<" Yen" <<endl;
    cout <<euro <<" Euros" <<endl;
    
    //Exit stage right
    return 0;
}