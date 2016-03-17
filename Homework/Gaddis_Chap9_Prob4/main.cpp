//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Function Prototypes
void arrSelectSort(int *, int *, int );
void showArray(int *, string *, int *, int);
void getData(int *, string *, int);
float getAvrg(int *, int);
int *fillIdx(int);
int getSize();

int main() {
    //Declare and Initialize Variables
    int numSize = getSize();
    float average;
    int *testScores = new int[numSize];
    string *names = new string[numSize];
    int *index = fillIdx(numSize);
    
    //Get Scores and Names
    getData(testScores, names, numSize);
    
    //Find the Average
    average = getAvrg(testScores, numSize);

    //Output Results
    cout << "The Scores you entered are: " <<endl;
    showArray(testScores, names, index, numSize);
    
    //Sort Scores
    arrSelectSort(testScores, index, numSize);
    
    //Output Sorted Scores
    cout << endl << "The Scores Sorted are: " <<endl;
    showArray(testScores, names, index, numSize);
    cout << endl;
    
    //Output the Average
    cout << "The average is " << average << endl;
    
    //Deallocate Memory
    delete []testScores;
    delete []index;
    delete []names;
    
    //Exit
    return 0;
}

void arrSelectSort(int *a, int *idx, int n) {
    for(int j=0; j<n; j++){
        for(int k = j+1; k < n; k++){
            if(a[j] > a[k]){
                int temp;
                temp = idx[j];
                idx[j] = idx[k];
                idx[k] = temp;
            }
        }
    }
}

void showArray(int *testScores, string *name, int *idx, int n) {
    cout <<"      Name   |   Score" <<endl;
    for (int i = 0; i < n; i++){
        cout <<setw(10) <<name[idx[i]] <<setw(10) <<testScores[idx[i]] <<endl;
    }
}

void getData(int *a, string *b, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter Student Number " << (i + 1) <<"'s name." << endl;
        cin >>b[i];
        cout <<"Enter " <<b[i] <<"'s test score" <<endl;
        cin >> a[i];
    }
}

float getAvrg(int *a, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += a[i];
    }
    return (total * 1.0f / n);
}

int *fillIdx(int n){
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        *(a+i) = i;
    }
    return a;
}

int getSize(){
    int a;
    cout <<"Enter the Number of students that tested." <<endl;
    cin >>a;
    return a;
}