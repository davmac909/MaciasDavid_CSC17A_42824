//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
void arrSelectSort(int *, int arySize);
void showArray(int *, int);
int *getScores(int &);
float getAvrg(int *, int);

int main() {
    //Declare and Initialize Variables
    int numSize;
    float average;
    int *testScores = getScores(numSize);
    
    //Find the Average
    average = getAvrg(testScores, numSize);

    //Output Results
    cout << "The Scores you entered are: ";
    showArray(testScores, numSize);
    
    //Sort Scores
    arrSelectSort(testScores, numSize);
    
    //Output Sorted Scores
    cout << endl << "The Scores Sorted are: ";
    showArray(testScores, numSize);
    cout << endl;
    
    //Output the Average
    cout << "The average is " << average << endl;
    
    //Deallocate Memory
    delete []testScores;
    
    //Exit
    return 0;
}

void arrSelectSort(int *testScores, int arySize) {
    int startScan, minIndex;
    int minElem;

    for (startScan = 0; startScan < (arySize - 1); startScan++) {
        minIndex = startScan;
        minElem = testScores[startScan];
        for (int index = startScan + 1; index < arySize; index++) {
            if (*(testScores + index) < minElem) {
                minElem = testScores[index];
                minIndex = index;
            }
        }
        testScores[minIndex] = testScores[startScan];
        testScores[startScan] = minElem;


    }

}

void showArray(int *testScores, int arySize) {
    for (int i = 0; i < arySize; i++)
        cout << testScores[i] << " ";
    cout << endl;
}

int *getScores(int &size) {
    cout << "How many scores would you like to enter?" << endl;
    cin >> size;
    int *a = new int[size];
    cout << "Enter your test scores " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Test number " << (i + 1) << ":" << endl;
        cin >> a[i];
    }
    return a;
}

float getAvrg(int *a, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }
    return (total * 1.0f / n);
}