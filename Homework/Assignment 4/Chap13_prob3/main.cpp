//System Libraries
#include <iostream>
#include "Car.h"
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Declare and initialize variables
    Car bug(1987, "Volkswagen");
    //Accelerate 5 times
    for(int i = 0; i < 5; i++){
        bug.accl();
    }
    //Output the speed
    cout <<"The " <<bug.getYrMdl() <<" " <<bug.getMake() 
            <<"'s current speed is " <<bug.getSpd() <<"." <<endl;
    //Brake 5 times
    for(int i = 0; i < 5; i++){
        bug.brake();
    }
    //Output speed
    cout <<"The car's final speed is " <<bug.getSpd() <<"." <<endl;
    //exit stage right
    return 0;
}
