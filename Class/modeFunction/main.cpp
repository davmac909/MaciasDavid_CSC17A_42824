//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
int *mode(int *, int);

//Execution Begins Here
int main(int argc, short** argv) {
    //Declare and initialize variables
    int arySize;
    int *point;
    
    //Input Data
    cout <<"Enter the amount of numbers in the list." <<endl;
    cin >>arySize;
    
    //Map inputs to outputs
    point = new int[arySize];
    
    for(int i = 0; i < arySize; i++){
        cout <<"Enter the " <<i+1 <<(i+1==1?"st":
                                     i+1==2?"nd":
                                     i+1==3?"rd":"th") <<" number." <<endl;
        cin >>*(point+i);
    }
    
    //Output the results
    mode(point, arySize);
    
    //Exit stage right
    delete[] point;
    return 0;
}

int *mode(int *, int){
    
}