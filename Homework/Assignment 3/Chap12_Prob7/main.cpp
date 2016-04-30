
//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    string inpt, outpt;
    ifstream inFile;
    ofstream outFile;
    char lttr, lttr2;
    
    cout <<"Enter the input text file name that exist in this project folder.(without the extension) i.e. \"Input File\"" <<endl;
    getline(cin, inpt);
    inpt += ".txt";
    inFile.open(inpt.c_str());
    
    if(inFile){
        cout <<"Enter the desired output file name." <<endl;
        getline(cin, outpt);
        outpt += ".txt";
        outFile.open(outpt.c_str());
        cout <<"The following was outputted to \"" <<outpt <<"\":" <<endl;
    
        inFile.get(lttr);
        lttr = toupper(lttr);
        outFile <<lttr;
        cout <<lttr;

        while(inFile){
            inFile.get(lttr);
            if(lttr == '.'){
                outFile <<lttr;
                cout <<lttr;
                inFile.get(lttr);
                if(inFile.peek() == '\n'){
                    outFile <<lttr;
                    cout <<lttr;
                    inFile.get(lttr);
                    lttr = toupper(lttr);
                    outFile <<lttr;
                    cout <<lttr;
                    inFile.get(lttr);
                    lttr = toupper(lttr);
                    outFile <<lttr;
                    cout <<lttr;
                }
                if(lttr == ' '){
                    outFile <<lttr;
                    cout <<lttr;
                    inFile.get(lttr);
                    lttr = toupper(lttr);
                    outFile <<lttr;
                    cout <<lttr;
                }
            }else{
               lttr = tolower(lttr);
               outFile <<lttr; 
               cout <<lttr;
            }
        }

        inFile.close();
        outFile.close();
    }else{
        cout <<"Error: File \"" <<inpt <<"\" does not exist." <<endl;
    }
    
    
    return 0;
}
