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
#include <fstream>
#include "Grid.h"
#include "Ship.h"
#include "Player.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
Ship *shpLoc(short);
Grid *drwGrid(Ship *, short, short);
void prntScrn(Grid *, Ship *, short, Player &);
void getInpt(Player &, bool &, bool &);
void hitMiss(Grid *, Ship *, Player &, short);
void getIntl(Player &);
void shwRank(Player &);
void gmEnd(Ship *, short , bool &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random time seed
    srand(static_cast<int>(time(0)));
    
    //Declare and initialize variables
    short nShips = 5;
    short nGrids = 2;
    Player player;
    Ship *ship = shpLoc(nShips);
    Grid *grid = drwGrid(ship, nShips, nGrids);
    short inRow, inCol;
    bool gameEnd = false;
    bool intl = true;
    clock_t tStrt, tEnd; //Start time and End time
    
    tStrt = time(0);
    do{
        //Print Game Screen
        prntScrn(grid, ship, nShips, player);
        //Determine game end
        gmEnd(ship, nShips, gameEnd);
        if(gameEnd){
            break;
        }
        //Get user inputs
        getInpt(player, intl, gameEnd);
        if(gameEnd){
            break;
        }
        //Check hit or Miss
        hitMiss(grid, ship, player, nShips);
    }while(!gameEnd);
    tEnd = time(0);
    //Calculate Game Time
    player.time = static_cast<short>(difftime(tEnd, tStrt));
    
    //Get Player's Initials
    getIntl(player);
     
    //Show Rankings
    shwRank(player);
    
    
    //Deallocate Memory
    for(int i = 0; i < nShips; i++){
        delete []ship[i].crdnts;
    }
    delete []ship;
    delete []grid;
    //Exit stage right
    return 0;
}

Ship *shpLoc(short n){
    Ship *a = new Ship[n];
    
    for(int i = 0; i < n; i++){
        switch(i){
            case 0:{
                a[i].shipL = 5;
                break;
            }case 1:{
                a[i].shipL = 4;
                break;
            }case 2:{
                a[i].shipL = 3;
                break;
            }case 3:{
                a[i].shipL = 3;
                break;
            }case 4:{
                a[i].shipL = 2;
                break;
            }
        }
        a[i].shipLtemp = a[i].shipL;
        a[i].shipX = rand()%(COL-a[i].shipL+1)+1;
        a[i].shipY = rand()%(ROW-a[i].shipL+1)+1;
    }
    return a;
}

Grid *drwGrid(Ship *b, short n, short g){
    Grid *a = new Grid[g];
    
    for(int i = 0; i < n; i++){
        b[i].crdnts = new Location[b[i].shipL];
    }
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
                    ortn = rand()%2;         //0 = horizontal, 1 = vertical
                    if(ortn == 1){ 
                        if(a[1].grid[i][j] == 'O'){
                            do{
                                j++;
                            }while(a[1].grid[i][j] == 'O');
                        }
                        while(i < b[s].shipY+b[s].shipL-1){
                            short t = i;
                            for(int v = 0; v < b[s].shipL; v++){
                                b[s].crdnts[v].xLoc = j;
                                b[s].crdnts[v].yLoc = t;
                                t--;
                            }
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
                            short t = j;
                            for(int v = 0; v < b[s].shipL; v++){
                                b[s].crdnts[v].xLoc = t;
                                b[s].crdnts[v].yLoc = i;
                                t--;
                            }
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

void prntScrn(Grid *a, Ship *s, short n, Player &p){
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
        if(i == 1){
            cout <<" Enemy Ships:";
        }if(i > 1){
            if(i < 7){
                cout <<" Ship: " <<i-1 <<"; " <<s[i-2].shipLtemp <<" Hits needed";
            }
        }if(i == 8){
            cout <<" Legend:";
        }if(i == 9){
            cout <<" 'H'-Hit, 'X'-Miss";
        }if(i == 11){
            cout <<" Bombs Remaining: " <<p.nbombs;
        }if(i == 12){
            cout <<" Total Hits: " <<p.totHit;
        }if(i == 13){
            cout <<" Total Misses: " <<p.totMiss;
        }
        cout <<endl;
    }
}

void getInpt(Player &p, bool &i, bool &end){
    string in;
    char a,b;
    do{
        if(i){
            cout <<"Welcome Green Horn!" <<endl;
            cout <<"Enter the letter and number you wish to strike " <<endl;
            cout <<"Then 'B' to order a bomb strike if desired." <<endl;
            cout <<"i.e. \"H9\" for a missile or \"H9B\" for a bomb" <<endl;
            cout <<"Or enter 'Q' to quit the game" <<endl;
            
        }else{
            cout <<"What's your next target?" <<endl;
        }
        getline(cin, in);

        stringstream ss(in);
        ss >>a >> p.inRow >>b;

        a = toupper(a);
        b = toupper(b);
        if(a == 'Q'){
            end = true;
            break;
        }
        p.inCol = static_cast<int>(a-65);
        p.inRow -= 1;
    }while((p.inCol < 0 || p.inCol > 15) || (p.inRow < 0 || p.inRow > 14));
    i = false;
    if(b == 'B'){
        b = ' ';
        if(!(p.nbombs == 0)){
            p.bomb = true;
            p.nbombs--;
        }else{
            cout <<"You are out of bombs." <<endl;
            cout <<"Missile strike en route" <<endl;
        }
    }
}

void hitMiss(Grid *g, Ship *s, Player &p, short n){
    if(p.bomb){
        p.bomb = false;
        for(short i = 0-1; i < 2; i++){
            for(short j = 0-1; j < 2; j++){
                if(g[1].grid[p.inRow+i][p.inCol+j] == 'O'){
                    g[1].grid[p.inRow+i][p.inCol+j] = 'H';
                    g[0].grid[p.inRow+i][p.inCol+j] = 'H';
                    p.totHit++;
                    for(int t = 0; t < n; t++){
                        for(int v = 0; v < s[t].shipL; v++){
                            if((p.inCol+j == s[t].crdnts[v].xLoc) && (p.inRow+i == s[t].crdnts[v].yLoc)){
                                s[t].shipLtemp--;
                            }
                        }
                    }
                }else if(g[1].grid[p.inRow+i][p.inCol+j] == '~'){
                    g[0].grid[p.inRow+i][p.inCol+j] = 'X';
                }
            }
        }
        p.totMiss++;
    }else{
        if(g[1].grid[p.inRow][p.inCol] == 'O'){
            g[1].grid[p.inRow][p.inCol] = 'H';
            g[0].grid[p.inRow][p.inCol] = 'H';
            p.totHit++;
            for(int t = 0; t < n; t++){
                for(int v = 0; v < s[t].shipL; v++){
                    if((p.inCol == s[t].crdnts[v].xLoc) && (p.inRow == s[t].crdnts[v].yLoc)){
                        s[t].shipLtemp--;
                    }
                }
            }
        }else if(g[1].grid[p.inRow][p.inCol] == '~'){
            g[0].grid[p.inRow][p.inCol] = 'X';
            p.totMiss++;
        }
    }
    p.ratio = 1.0f*p.totHit/(p.totHit+p.totMiss);
}

void getIntl(Player &p){
    ofstream out;
    out.open("scores.dat",ios::binary | ios::app);
    cout <<"Game End:" <<endl;
    cout <<" Game Time(sec) - " <<p.time <<endl;
    cout <<" Bombs Remaining - " <<p.nbombs <<endl;
    cout <<" Hits - " <<p.totHit <<endl;
    cout <<" Misses - " <<p.totMiss <<endl;
    cout <<" Hits per strikes called - " <<p.ratio <<endl;
    cout <<" Your Initials: ";
    cin.getline(p.intls, NSIZE);
    
    //Write player information to file in binary
    out.write(reinterpret_cast<char *>(&p), sizeof(p));
    //Close file
    out.close();
}

void shwRank(Player &p){
    ifstream in;
    in.open("scores.dat",ios::binary);
    if(in){
        //Output file data
        cout <<endl <<endl <<"Rankings" <<endl;
        in.read(reinterpret_cast<char *>(&p), sizeof(p));
        cout <<"Initials | Hit/Total Strikes | Hits | Misses | Bombs Left | Game Time(sec)" <<endl;
        while(!in.eof()){
            cout <<setw(6) <<p.intls 
                    <<setw(16) <<showpoint <<setprecision(2) <<p.ratio
                    <<setw(11) <<p.totHit <<setw(8) <<p.totMiss
                    <<setw(13) <<p.nbombs <<setw(12) <<p.time <<endl;
            in.read(reinterpret_cast<char *>(&p), sizeof(p));
        }
    }else{
        cout <<"Error: Couldn't open \"scores.dat\"" <<endl;
    }
    //close file
    in.close();
}

void gmEnd(Ship *s, short n, bool &b){
    short temp;
    for(int i = 0; i < n; i++){
        temp += s[i].shipLtemp;
        if(temp == 0){
            b = true;
        }
    }
}