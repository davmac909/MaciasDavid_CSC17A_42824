//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here
int main(int argc, short** argv) {
    //Declare and initialize variables
    ifstream inFile;
    ofstream outFile;
    const int SIZE = 3;
    string names[SIZE];
    
    //Input Data
    inFile.open("Names.txt");
    
    for(int i=0; i<SIZE; i++){
        getline(inFile, names[i]);
    }
   
    //Sort Names
    for(int j=0; j<SIZE; j++){
        for(int k = j+1; k < SIZE; k++){
            if(names[j] > names[k]){
                string temp;
                temp = names[j];
                names[j] = names[k];
                names[k] = temp;
            }
        }
    }
    
    //Output to file
    outFile.open("NamesSorted.txt");
    for(int h=0; h<SIZE; h++){
        outFile <<names[h] <<endl;
    }
    
    //Exit stage right
    outFile.close();
    inFile.close();
    //outFile.close();
    return 0;
}
