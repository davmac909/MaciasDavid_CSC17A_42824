//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int);
int *fillIndx(int);
int *fillMod(int, int);
void prntAry(int *, int, int);
void markSrt(int *, int);
int *mode(int *, int);
void prntMod(int *, int);
float findAverage(int *a, int n);
float median(int*, int);




//Execution Begins Here
int main(int argc, char** argv) {
	//Seed the random number generator
	srand(static_cast<unsigned int>(time(0)));
	//Declare and allocate the array
	int size = 99;
	int *array = fillAry(size);
	float mean;
        float medn;
	//Display the random array
	prntAry(array, size, 10);
	//Sort the array
	markSrt(array, size);
	//Display the random array
	prntAry(array, size, 10);
	int *mod = mode(array, size);
       // cout <<"Mode array is :" <<endl;
	//prntMod(mod);
        cout <<endl;
	cout << "The average of the array " << endl;
	mean = findAverage(array, size);
        cout <<mean;
        cout <<endl;
        cout << "The median of the fuction is " << endl;
        medn = median(array, size);
        cout <<medn;
	//Deallocate Memory
	delete[]array;
	//Exit stage right
	return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Print Array
//Inputs
//     n->Size of the array
//     a->Array
//Output
//     a->The sorted array
////////////////////////////////////////////////////////////////////////////////
void markSrt(int *a, int n) {
	for (int pos = 0; pos<n - 1; pos++) {
		for (int row = pos + 1; row<n; row++) {
			if (*(a + pos)>*(a + row)) {
				*(a + pos) = *(a + pos) ^ *(a + row);
				a[row] = a[pos] ^ a[row];
				*(a + pos) = *(a + pos) ^ *(a + row);
			}
		}
	}
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Print Array
//Inputs
//     n->Size of the array
//     a->Array
//     perLine->Number of integers to display per row
////////////////////////////////////////////////////////////////////////////////
void prntAry(int *a, int n, int perLine) {
	//Output the Array
	cout << endl;
	for (int i = 0; i<n; i++) {
		cout << *(a + i) << " ";
		if (i%perLine == (perLine - 1))cout << endl;
	}
	cout << endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                        Fill Mode Array with mod
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with repeated numbers
////////////////////////////////////////////////////////////////////////////////
int *fillMod(int n, int mod) {
	//Declare and allocate memory
	int *a = new int[n];
	//Loop and fill with repetitive numbers
	for (int i = 0; i<n; i++) {
		*(a + i) = i%mod;
	}
	//return the pointer
	return a;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Fill Array
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *fillAry(int n) {
	//Declare and allocate memory
	int *a = new int[n];
	//Loop and fill with 2 digit numbers
	for (int i = 0; i<n; i++) {
		*(a + i) = rand() % 90 + 10;
	}
	//return the pointer
	return a;
}

int *mode(int *a, int n)
{
    int modeArraySize = 2;
	int freq = 1;
        int maxFreq = 1;
	for (int i = 0; i < n; i++)
	{
                    if(a[i] == a[i+1]){
                        freq++;
                        if(freq > maxFreq){
                            maxFreq = freq;
                        }
                    }else{
                        freq = 1;
                    }
                }
        
        for (int i = 0; i < n; i++)
	{
                    if(a[i] == a[i+1]){
                        freq++;
                        if(freq == maxFreq){
                            modeArraySize++;
                        }
                    }else{
                        freq = 1;
                    }
                }
        int *b = new int[modeArraySize];
        
        b[0] = modeArraySize-2;
        b[1] = maxFreq;
        int startModes = 2;
        for (int i = 0; i < n; i++)
	{
                    if(a[i] == a[i+1]){
                        freq++;
                        if(freq == maxFreq){
                            b[startModes] = a[i];
                            startModes++;
                        }
                    }else{
                        freq = 1;
                    }
                }
        prntMod(b, modeArraySize);
}
         

void prntMod(int *a, int n)
{
//Output the Array
	cout << endl;
        cout <<"Mode array is: ";
	for (int i = 0; i<n; i++) {
		cout << *(a + i) << " ";
	}
	cout << endl;
}

float median(int *a, int n)
{
    
    cout <<n/2 <<endl;
        return a[n/2];
}

float findAverage(int *a, int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		total += a[i];
	}


	return (total*1.0f/n);
}