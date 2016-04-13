
//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Functional Prototypes
float Celsius(float);
//Execution Begins Here
int main(int argc, char** argv) {
    float fah = 20;
    float cel;
    
    cout <<"Fahrenheit | Celsius" <<endl;
    for(float i = 0; i <= fah; i++){
        cel = Celsius(i);
        cout <<setw(2) <<i <<"           " <<cel <<endl;
    }
    return 0;
}

float Celsius(float a){
    float b;
    b = (a-32)*5/9;
    return b;
}