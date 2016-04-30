
//System Libraries
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
void ary2File(string, int *, int);
void file2Ary(string, int *, int);

//Execution Begins Here
int main(int argc, char** argv) {
    srand(static_cast<int>(time(0)));
    
    string fileNam;
    int size = 100;
    int *ary1 = new int[size];
    int *ary2 = new int[size];
    
    for(int i = 0; i < size; i++){
        ary1[i] = rand()%99+1;
    }
    
    cout <<"Enter the file name to write contents to without the file extension." <<endl;
    getline(cin, fileNam);
    fileNam += ".txt";
    
    ary2File(fileNam, ary1, size);
    file2Ary(fileNam, ary2, size);
    
    cout <<"Number in file: " <<endl;
    for(int i = 0; i < size; i++){
        cout <<*(ary2+i) <<" ";
    }
    
    delete []ary1;
    delete []ary2;
    return 0;
}

void ary2File(string s, int *a, int n){
    ofstream file;
    file.open(s.c_str(), ios::binary);
    file.write(reinterpret_cast<char *>(a), sizeof(int)*n);
    file.close();
    
    
}

void file2Ary(string s, int *a, int n){
    ifstream file;
    file.open(s.c_str(), ios::binary);
    file.read(reinterpret_cast<char *>(a), sizeof(int)*n);
    file.close();
}