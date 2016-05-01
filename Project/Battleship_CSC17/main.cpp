/* 
 * Author: David Macias
 * Created on January 25, 2016, 11:28 PM
 * Purpose: CSC 5 Project 1: Battleship
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "Grid.h"
#include "Ship.h"
#include "Player.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
Ship *shpLoc(short);
Grid *drwGrid(Ship *, short, short);
void prntScrn(Grid *, Ship *, short, Player *);
void getInpt(Player *, bool &);
void hitMiss(Grid *, Ship *, Player *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random time seed
    srand(static_cast<int>(time(0)));
    
    //Declare and initialize variables
    short nShips = 5;
    short nGrids = 2;
    short nPlyrs = 1;
    Player *player = new Player[nPlyrs];
    Ship *ship = shpLoc(nShips);
    Grid *grid = drwGrid(ship, nShips, nGrids);
    short inRow, inCol;
    bool win = false;
    bool intl = true;
    
    do{
    //Print Game Screen
    prntScrn(grid, ship, nShips, player);
    //Get user inputs
    getInpt(player, intl);
    //Check hit or Miss
    hitMiss(grid, ship, player);
    }while(!win);
    
    delete []ship;
    delete []grid;
    delete []player;
    return 0;
}

Ship *shpLoc(short n){
    Ship *a = new Ship[n];
    
    for(int i = 0; i < n; i++){
        a[i].shipL = rand()%4+2;
        a[i].shipX = rand()%(COL-a[i].shipL+1)+1;
        a[i].shipY = rand()%(ROW-a[i].shipL+1)+1;
    }
    return a;
}

Grid *drwGrid(Ship *b, short n, short g){
    Grid *a = new Grid[g];
    short ortn;
    for(int h = 0; h < g; h++){
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                a[h].grid[i][j] = '~';
            }
        }
    }
    for(int s = 0; s < n; s++){
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(j == b[s].shipX-1 && i == b[s].shipY-1){
                    ortn = rand()%2;
                    if(ortn == 1){ 
                        if(a[1].grid[i][j] == 'O'){
                            do{
                                j++;
                            }while(a[1].grid[i][j] == 'O');
                        }
                        while(i < b[s].shipY+b[s].shipL-1){
                            a[1].grid[i][j] = 'O';
                            i++;
                        }
                    }else{
                        if(a[1].grid[i][j] == 'O'){
                            do{
                                i++;
                            }while(a[1].grid[i][j] == 'O');
                        }
                        while(j < b[s].shipX+b[s].shipL-1){
                            a[1].grid[i][j] = 'O';
                            j++;
                        }
                    }
                }
            }
        }
    }
    return a;
}

void prntScrn(Grid *a, Ship *s, short n, Player *p){
    cout <<"  ";
    for(int i = 65, j = 0; j < COL; j++, i++){
            cout <<" " <<static_cast<char>(i);       //Print Letters for Columns
        }
    cout <<endl;
    for(int i = 0; i < ROW; i++){
        cout <<setw(2) <<i+1; //Numbers for rows
        for(int j = 0; j < COL; j++){
            cout <<" " <<a[0].grid[i][j];
        }
        if(i == 2){
            cout <<" Enemy Ships:";
        }else if(i > 2){
            if(i < 8){
                cout <<" Ship: " <<i-2 <<"; " <<s[i-3].shipL <<" Hits needed";
            }
        }if(i == 9){
            cout <<" Legend:";
        }if(i == 10){
            cout <<" 'H'-Hit, 'X'-Miss";
        }if(i == 12){
            cout <<" Nukes Remaining: " <<p->nbombs;
        }
        cout <<endl;
    }
}

void getInpt(Player *p, bool &i){
    string in;
    char a,b;
    
    if(i){
        cout <<"Welcome Green Horn!" <<endl;
        cout <<"Enter the letter and number you wish to strike " <<endl;
        cout <<"Then 'B' to order a nuke strike." <<endl;
        cout <<"i.e. \"H9\" for a single strike or \"H9B\" for a nuke" <<endl;
        i = false;
    }else{
        cout <<"What's your next target?" <<endl;
    }
    getline(cin, in);
    
    stringstream ss(in);
    ss >>a >> p->inRow >>b;
    a = toupper(a);
    b = toupper(b);
    p->inCol = static_cast<short>(a-65);
    p->inRow -= 1;
    cout <<p->inCol <<" " <<p->inRow;
    cout <<endl;
    if(b == 'B'){
        if(!(p->nbombs == 0)){
            p->bomb = true;
            p->nbombs--;
        }else{
            cout <<"You are out of nukes." <<endl;
            cout <<"Single shot en route" <<endl;
        }
    }
}

void hitMiss(Grid *g, Ship *s, Player *p){
    cout <<p->inCol <<" " <<p->inRow;
    cout <<endl;
    if(g[1].grid[p->inRow][p->inCol] == 'O'){
        g[0].grid[p->inRow][p->inCol] = 'H';
        p->totHit++;
    }else{
        g[0].grid[p->inRow][p->inCol] = 'X';
        p->totMiss++;
    }
}