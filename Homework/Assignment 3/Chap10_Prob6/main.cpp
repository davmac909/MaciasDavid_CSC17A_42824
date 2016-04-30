
//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
short vowels(char *);
short cnsnts(char *);
void toUpper(char *);

//Execution Begins Here
int main(int argc, char** argv) {
    const short SIZE = 50;
    char phrase[SIZE];
    char choice;
    short vwls, cnst;
    
    cout <<"Enter a phrase." <<endl;
    cin.getline(phrase, SIZE);
    toUpper(phrase);
    vwls = vowels(phrase);
    cnst = cnsnts(phrase);
    
    do{
        cout <<endl;
        cout <<"Enter the letter of your choice." <<endl;
        cout <<"A) Count the number of vowels in the string" <<endl;
        cout <<"B) Count the number of consonants in the string" <<endl;
        cout <<"C) Count both the vowels and consonants in the string" <<endl;
        cout <<"D) Enter another string" <<endl;
        cout <<"E) Exit the program" <<endl;

        cin >>choice;

        choice = toupper(choice);

        switch(choice){
            case 'A':{
                cout <<"The number of vowels in the string is " <<vwls <<endl;
                break;
            }case 'B':{
                cout <<"The number of consonants in the string is " <<cnst <<endl;
                break;
            }case 'C':{
                cout <<"The number of both consonants and vowels in the string is "
                        <<vwls+cnst <<endl;
                break;
            }case 'D':{
                cout <<"Enter another phrase." <<endl;
                cin.ignore();
                cin.getline(phrase, SIZE);
                toUpper(phrase);
                vwls = vowels(phrase);
                cnst = cnsnts(phrase);
                break;
            }case 'E':{
                return 0;
            }
        }
    }while(choice == 'A' || choice == 'B' || choice == 'C' || choice == 'D');
}

short vowels(char *a){
    short num = 0;
    for(int i = 0; i < strlen(a); i++){
        if(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
            num++;
        }
    }
    return num;
}

short cnsnts(char *a){
    short num = 0;
    for(int i = 0; i < strlen(a); i++){
        if(!(a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')){
            if(!(a[i] == ' ' || a[i] == '\'' || a[i] == ',' || a[i] == '.')){
                if(!isdigit(a[i])){
                    num++;
                }
            }
        }
    }
    return num;
}

void toUpper(char *a){
    for(int i = 0; i < strlen(a); i++){
        a[i] = toupper(a[i]);
    }
}