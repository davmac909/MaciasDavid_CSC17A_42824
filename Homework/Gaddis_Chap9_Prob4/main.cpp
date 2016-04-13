//System Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//Function Prototypes
int *fllCrCd(int, int);
int *luhnAlg(int *, int);
int sum(int *, int);
void dispAry(int *, int);

int main() {
    //Set random time seed
    srand(static_cast<int>(time(0)));
    
    //Declare and Initialize Variables
    enum crCard {visa, mstrCd, disc, amExp};
    const int size = 16;
    int total = 0;
    int card = rand()%4+1;
    cout <<crCard(card) <<endl;
    
    do{
        int *cdNum = fllCrCd(size, 4);
        int wghtAry[size] = {2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1};
        int *luhnAry = luhnAlg(cdNum, size);
        total = sum(luhnAry, size);

        cout <<"The Card number is: ";
        dispAry(cdNum, size);
        cout <<"The weight Numbers are: ";
        for(int i = 0; i < size; i++){
            cout <<wghtAry[i] <<" ";
        }
        cout <<endl;
        cout <<"Multiple Number is: ";
        dispAry(luhnAry, size);
        cout <<"The sum of the Numbers is: ";
        cout <<total <<endl;

        //Deallocate memory
        delete []luhnAry;
        delete []cdNum;
    }while(total%10 != 0);
    
    //Exit
    return 0;
}

int *fllCrCd(int n, int b){
    int *a = new int[n];
    switch (b){
        case 1: 
            for(int i = 0; i < n; i++){
                if(i == 0){
                    a[i] = 4;
                }else{
                    a[i] = rand()%10;
                }
            }
            break;
        case 2: 
            for(int i = 0; i < n; i++){
                if(i == 0){
                    a[i] = 5;
                }else if(i == 1){
                    a[i] == rand()%5+1;
                }else{
                    a[i] = rand()%10;
                }
            }
            break;
        case 3: 
            a[0] = 6;
            a[1] = 0;
            a[2] = 1;
            a[3] = 1;
            for(int i = 4; i < n; i++){
                a[i] = rand()%10;
            }
            break;
        case 4: {
            a[0] = 3;
            int m = rand()%2;
            cout << m;
            if(m == 1){
                a[1] = 4;
            }else{
                a[1] = 7;
            }
            for(int i = 2; i < n-1; i++){
                    a[i] = rand()%10;
            }
            break;
    }
    }
    return a;
}

int *luhnAlg(int *a, int n){
    int b[n] = {2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1};
    int *c = new int[n];
    for(int i = 0; i < n; i++){
        c[i] = a[i]*b[i];
        if(c[i] > 9){
            c[i] -= 9;
        }
    }
    return c;
}

int sum(int *a, int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s += a[i];
    }
    return s;
}

void dispAry(int *a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i];
    }
    cout <<endl;
}