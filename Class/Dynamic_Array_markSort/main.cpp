//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
int *fllArry(int);
void prntAry(int *, int, int);
void markSrt(int *, int);
int *fllMod(int, int);
int *mode(int *, int);
void prntMod(int *, int);

//Execution Begins Here
int main(int argc, short** argv) {
    //Seed the random Number Generator
    srand(static_cast<int>(time(0)));
    
    //Declare and initialize variables
    int size = 100;
    int *array = fllArry(size);
    int *modeAry = fllMod(size, 10);
    
    //Output the results
    prntAry(array, size, 10);
    
    //Sort Array
    markSrt(array, size);
    
    //Output the results
    prntAry(array, size, 10);
    
    //Deallocate Memory
    delete []array;
    
    //Exit stage right
    return 0;
}
/******************************************************************************/
/*****************************Fill Array***************************************/
/******************************************************************************/
//Inputs:
//  n-> size of array
//Outputs:
//  a-> array with random numbers
int *fllArry(int n){
    //Declare and allocate memory
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        *(a+i) = rand()%90+10;
    }
    return a;
}

/******************************************************************************/
/*****************************Fill Mode Array**********************************/
/******************************************************************************/
//Inputs:
//  n-> size of array
//Outputs:
//  a-> array with random numbers
int *fllMod(int n, int mod){
    //Declare and allocate memory
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        *(a+i) = i%mod;
    }
    return a;
}

/******************************************************************************/
/*****************************Print Array**************************************/
/******************************************************************************/
//Inputs:
//  a-> array with random numbers
//  n-> size of array
//  perLine-> number of numbers to display per row
void prntAry(int *a, int n, int perLine){
    //Output the Array
    cout <<endl;
    for(int i = 0; i < n; i++){
        cout <<a[i] <<" ";
        if(i%perLine == (perLine-1)){
            cout <<endl;
        }
    }
}

/******************************************************************************/
/*****************************Mark Sort****************************************/
/******************************************************************************/
//Inputs:
//  a-> array with random numbers
//  n-> size of array
//  perLine-> number of numbers to display per row
void markSrt(int *a, int n){
    for(int pos = 0; pos < n-1; pos++){
        for(int row = pos+1; row < n; row++){
            if(a[pos] > a[row]){
                int temp;
                temp = a[pos];
                a[pos] = a[row];
                a[row] = temp;
            }
        }
    }
}