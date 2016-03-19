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
int *fllIndx(int);
void prntAry(int *, int *, int, int);
void markSrt(int *, int *, int);
int *fllMod(int, int);
void mode(int *, int *, int);
//void prntMod(int *, int);
float median(int *, int *, int);
float mean(int *, int *, int);
int getMdSz(int *, int *, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random Number Generator
    srand(static_cast<int>(time(0)));
    
    //Declare and initialize variables
    int size = 100;
    int *array = fllArry(size);
    int *index = fllIndx(size);
    
    float med, mn;
    
    //Output the results
    cout <<"Unsorted array:" <<endl;
    prntAry(array, index, size, 10);
    
    //Sort Array
    markSrt(array, index, size);
    
    //Find the Median and Mean
    med = median(array, index, size);
    mn = mean(array, index, size);
    
    //Output the results
    cout <<"Sorted array:" <<endl;
    prntAry(array, index, size, 10);
    cout <<"Median = " <<med <<endl;
    cout <<"Mean   = " <<mn <<endl;
    cout <<"Mode array = " <<endl;
    mode(array, index, size);
    
    //Deallocate Memory
    delete []array;
    delete []index;
    //delete []mod;
    
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
/*****************************Fill Index***************************************/
/******************************************************************************/
//Inputs:
//  n-> size of array
//Outputs:
//  a-> array with random numbers
int *fllIndx(int n){
    //Declare and allocate memory
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        *(a+i) = i;
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
void prntAry(int *a, int *b, int n, int perLine){
    //Output the Array
    for(int i = 0; i < n; i++){
        cout <<a[b[i]] <<" ";
        if(i%perLine == (perLine-1)){
            cout <<endl;
        }
    }
    cout <<endl;
}

/******************************************************************************/
/*****************************Mark Sort****************************************/
/******************************************************************************/
//Inputs:
//  a-> array with random numbers
//  n-> size of array
//  perLine-> number of numbers to display per row
void markSrt(int *a, int *indx, int n){
    for(int pos = 0; pos < n-1; pos++){
        for(int row = pos+1; row < n; row++){
            if(a[indx[pos]] > a[indx[row]]){
                int temp;
                temp = indx[pos];
                indx[pos] = indx[row];
                indx[row] = temp;
            }
        }
    }
}

float median(int *a, int *b, int n){
    float median;
    if(n%2 == 0){
        median = (*(a+*(b+(n/2)))+*(a+*(b+((n/2)-1))))*1.0f/2;
    }else{
        median = *(a+*(b+(n/2)));
    }
    return median;
}

float mean(int *a, int *b, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[b[i]];
    }
    return (sum*1.0f/n);
}

void mode(int *ary, int *indx, int n){
    int modeSz = 2;
    int freq = 1;
    int maxFreq = 1;
    cout <<"Number  |  Times repeated" <<endl;
    for(int i = 0; i < n; i++){
        if(freq == 1){
            cout <<setw(4) <<ary[indx[i]] <<setw(8);
        }
         cout <<freq <<" ";
        if(*(ary+*(indx+i)) == ary[indx[i+1]]){
            freq++;
            if(freq > maxFreq){
                maxFreq = freq;
            }
        }else{
            cout <<endl;
            freq = 1;
        }
    }
    
    modeSz += getMdSz(ary, indx, n, maxFreq);
    
    cout <<"Max Frequency: " <<maxFreq <<endl;
    cout <<"Mode array size: " <<modeSz <<endl;
}

int getMdSz(int *ary, int *indx, int n, int maxFreq){
    int freq = 1;
    int size = 0;
    for(int i = 0; i < n; i++){
        if(*(ary+*(indx+i)) == ary[indx[i+1]]){
            freq++;
            if(freq == maxFreq){
                size++;
            }
        }else{
            freq = 1;
        }
    }
    return size;
}