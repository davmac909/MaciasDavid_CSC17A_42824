
//System Libraries
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here


int main(int argc, char** argv) {
    //Declare and initialize variables
    float tmpCel, tmpF;
    
    //Input Data
    cout<<"Input the degrees in Celsius:"<<endl;
    cin>>tmpCel;
    
    //Calculate or map inputs to outputs
    tmpF=1.8f*tmpCel+32;
    
    //Output the results
    cout<<"Degrees in Celsius = "<<tmpCel<<endl;
    cout<<"Degrees in Fahrenheit = "<<tmpF<<endl;
    
    //Exit stage right
    return 0;
}