
//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
short numWrds(char *);
short avrg(char *, short);

//Execution Begins Here
int main(int argc, char** argv) {
    const short SIZE = 50;
    char phrase[SIZE];
    short wrds;
    short avg;
    cout <<"Enter a phrase no more than 50 characters to count the number of words in." <<endl;
    cin.getline(phrase, SIZE);
    wrds = numWrds(phrase);
    cout <<"The number of words in the phrase is: ";
    cout <<wrds <<endl;
    avg = avrg(phrase, wrds);
    cout <<"The average number of letters per word is: ";
    cout <<avg <<endl;
    
    
    
    return 0;
}

short numWrds(char *a){
    short num = 0;
    
    for(int i = 0; i < strlen(a); i++){
        if(a[i] == ' '){
            num++;
        }
    }
    return (num+1);
}

short avrg(char *a, short w){
    short num = 0;
    
    for(int i = 0; i < strlen(a); i++){
        if(!(a[i] == ' ' || a[i] == '\'' || a[i] == ',' || a[i] == '.')){
            num++;
        }
    }
    cout <<num;
    return (num/w);
}