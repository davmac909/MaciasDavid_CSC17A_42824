
//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes

//Execution Begins Here


int main(int argc, char** argv) {
    int orgn;
    int endOrgn;
    float prct;
    int days;
    
    do{
        cout <<"Enter the Starting number of organisms that is greater than 2." <<endl;
        cin >>orgn;
    }while(orgn < 2);
    
    do{
        cout <<"Enter the daily population increase as a percentage that is not a negative value." <<endl;
        cin >>prct;
    }while(prct < 0);
    
    do{
        cout <<"Enter the number of days they will multiply that is not less than 1." <<endl;
        cin >>days;
    }while(days < 1);
    
    cout <<"After " <<days <<" days " <<orgn <<" organisms will populate to ";
    
    for(int i = 1; i <= days; i++){
        orgn += (orgn*prct*1.0f/100);
    }
    
    cout <<orgn <<" organisms when their daily population increase as a percentage is " <<prct;
    
    
    return 0;
}