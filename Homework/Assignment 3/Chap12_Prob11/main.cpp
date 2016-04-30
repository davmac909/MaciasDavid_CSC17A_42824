
//System Libraries
#include <iostream>
#include <fstream>
#include <string>

#include "Company.h"
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    Company business; //to hold data about a business's division
    char answr; //to repeat getting data
    const short SIZE = 4; //size of arrays for storing in data from file
    string dvsn[SIZE] = {};
    float qrtrSales[SIZE][SIZE] = {};
    string temp;
    float total = 0;
    float most = 0, least = 10000;
    short hghst, lwst;
    
    //Select option
    cout <<"Type 's' to save company data, 'd' to display calculated totals"
            " of previously saved data in file, or anything else to exit." <<endl;
    cin >>answr;
    answr = toupper(answr);
    
    switch(answr){
        case 'S':{
            cin.ignore();  //Clear last newline
            ofstream out; //Output file
            out.open("sales.txt", ios::binary); //open file for binary output
            //get each division name
            for(int i = 0; i < SIZE; i++){
                //get division name
                cout <<"what is the name of the division?" <<endl;
                cin.getline(business.dvsName, NAMSIZE);
                //get each quarterly sales
                for(int j = 0; j < SIZE; j++){
                    business.qtr = j;
                    //get only quarterly sales greater than zero
                    do{
                        cout <<"Enter the quarterly sales for quarter number " 
                            <<business.qtr+1 <<endl;
                        cin >>business.qtrSale;
                    }while(business.qtrSale < 0);
                    //write contents to file
                    out.write(reinterpret_cast<char *>(&business), sizeof(business));
                    cin.ignore(); 
                }
            }
            //close the file
            out.close();

        }case 'D':{
            ifstream in; //file for input
            in.open("sales.txt", ios::binary); //Open file to read in binary

            if(in){
                //Get data from file
                in.read(reinterpret_cast<char *>(&business), sizeof(business));
                //Declare and initialize variables
                int index = 0;      //counter for division
                int indx = 0;       //counter for quarter
                bool fst = false;   //becomes true after first loop of getting data

                while(!in.eof()){

                    if(fst){
                        if(indx%4 == 0){

                            index++;
                        }
                    }
                    //Map inputs
                    temp = business.dvsName;
                    dvsn[index] = temp;
                    qrtrSales[index][business.qtr] = business.qtrSale;
                    //Read in data from file again
                    in.read(reinterpret_cast<char *>(&business), sizeof(business));
                    indx++;
                    fst = true;
                }
                in.close();
            }else{
                cout <<"Error: Could not open file." <<endl;
            }

            //Output total corporate sales
            cout <<endl;
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j <SIZE; j++){
                    total += qrtrSales[j][i];
                }
                if(total > most){
                    most = total;
                    hghst = i;
                }if(total < least){
                    least = total;
                    lwst = i;
                }
                cout <<"The total corporate sales for quarter number " 
                        <<i+1 <<" is: " <<total <<endl;
                cout <<"    The average sales for this quarter is: "
                        <<total/SIZE <<endl;
                total = 0;
            }
            //Output total yearly sales for each division
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j <SIZE; j++){
                    total += qrtrSales[i][j];
                }
                cout <<"The total yearly sales for the " 
                        <<dvsn[i] <<" division is: " <<total <<endl;
                total = 0;
            }
            //Output total yearly corporate sales
            for(int i = 0; i < SIZE; i++){
                for(int j = 0; j <SIZE; j++){
                    total += qrtrSales[i][j];
                }
            }
            //Output yearly sales, highest, and lowest quarters
            cout <<"The total yearly sales for the Company is: " 
                        <<total <<endl;
            cout <<"The highest quarter for the company is: " <<hghst+1 <<endl;
            cout <<"The lowest quarter for the company is: " <<lwst+1 <<endl;
        }
    }
    return 0;
}
