/* 
 * Author: David Macias
 * Created on May 4, 2016, 05:56 PM
 * Purpose: CSC 17A Project: Battleship
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Player.h"
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
Ship *shpLoc(Player);
Grid *drwGrid(Player &);
void prntScrn(Player &, Player &);
void getInpt(Player &, bool &, bool &);
void hitMiss(Grid *, Ship *, Player &, short);
void getIntl(Player &);
void shwRank(Player &);
void gmEnd(Player, Player, bool &);
bool dspMenu();
void mkShpG(Player &, Player);
void cmpInpt(Player &, Player);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the random time seed
    srand(static_cast<int>(time(0)));
    
    //Declare and initialize variables
    Player user;
    Player comp;
    user.orgn = dspMenu();
    user.nGrids = 2;
    user.shipG = 0;
    user.dispG = 1;
    comp.nGrids = 2;
    comp.dispG = 0;
    comp.shipG = 1;
    comp.ship = shpLoc(comp);
    comp.grid = drwGrid(comp);
    if(user.orgn){
        mkShpG(user, comp);
        user.strt = true;
    }else{
        user.strt = true;
        user.ship = shpLoc(user);
        user.grid = drwGrid(user);
    }
    
    cout <<endl <<endl <<setw(60) <<"GAME ON!" <<endl;
    prntScrn(user, comp);
    /*
    bool gameEnd = false;
    bool intl = true;
    clock_t tStrt, tEnd; //Start time and End time
    
    tStrt = time(0);
    do{
        //Print Game Screen
        prntScrn(user, comp);
        //Determine game end
        gmEnd(user, comp, gameEnd);
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
     * 
     * 
     * */
    //Exit stage right
    return 0;
}



Ship *shpLoc(Player p){
    Ship *a = new Ship[p.nShips];
    
    for(int i = 0; i < p.nShips; i++){
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

Grid *drwGrid(Player &p){
    Grid *a = new Grid[p.nGrids];
    
    for(int i = 0; i < p.nShips; i++){
        p.ship[i].crdnts = new Location[p.ship[i].shipL];
    }
    short ortn;
    for(int h = 0; h < p.nGrids; h++){
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){ 
               a[h].grid[i][j] = '~';
            }
        }
    }
    for(int s = 0; s < p.nShips; s++){
        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(j == p.ship[s].shipX-1 && i == p.ship[s].shipY-1){
                    if(!p.orgn){
                        p.ship[s].ortn = rand()%2;         //0 = horizontal, 1 = vertical
                    }
                    if(p.ship[s].ortn == 1){ 
                        if(a[p.shipG].grid[i][j] == 'O'){
                            do{
                                j++;
                            }while(a[p.shipG].grid[i][j] == 'O');
                        }
                        while(i < p.ship[s].shipY+p.ship[s].shipL-1){
                            short t = i;
                            for(int v = 0; v < p.ship[s].shipL; v++){
                                p.ship[s].crdnts[v].xLoc = j;
                                p.ship[s].crdnts[v].yLoc = t;
                                t--;
                            }
                            a[p.shipG].grid[i][j] = 'O';
                            i++;
                        }
                    }else{
                        if(a[p.shipG].grid[i][j] == 'O'){
                            do{
                                i++;
                            }while(a[p.shipG].grid[i][j] == 'O');
                        }
                        while(j < p.ship[s].shipX+p.ship[s].shipL-1){
                            short t = j;
                            for(int v = 0; v < p.ship[s].shipL; v++){
                                p.ship[s].crdnts[v].xLoc = t;
                                p.ship[s].crdnts[v].yLoc = i;
                                t--;
                            }
                            a[p.shipG].grid[i][j] = 'O';
                            j++;
                        }
                    }
                }
            }
        }
    }
    return a;
}

void prntScrn(Player &p, Player &c){
    cout <<setw(22) <<"YOUR BOARD" <<setw(77) <<"ENEMY'S BOARD" <<endl;
    cout <<"  ";
    for(int i = 65, j = 0; j < COL; j++, i++){
            cout <<" " <<static_cast<char>(i);       //Print Letters for Columns
        }
    if(p.strt){
        cout <<setw(45);
        for(int i = 65, j = 0; j < COL; j++, i++){
                cout <<" " <<static_cast<char>(i);       //Print Letters for Columns
            }
    }
    
    cout <<endl;
    for(int i = 0; i < ROW; i++){
        cout <<setw(2) <<i+1; //Numbers for rows
        for(int j = 0; j < COL; j++){
            cout <<" " <<p.grid[p.shipG].grid[i][j];
        }
        if(p.strt){
            if(i == 1){
            cout <<" Your Ships:";
            }if(i > 1){
                if(i < 7){
                    cout <<" Ship " <<i-1 <<": " <<p.ship[i-2].shipLtemp <<"/" 
                            <<p.ship[i-2].shipL <<" Hits Remaining";
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
            //////////////////////////COMP GRID///////////////////////////
            if(i == 0 || i == 7 || i == 10 || i == 14){
                cout <<setw(44);
            }
            if(i == 1){
                cout <<setw(32);
            }if(i > 1){
                if(i < 7){
                    cout <<setw(17);
                }
            }if(i == 8){
                cout <<setw(36);
            }if(i == 9){
                cout <<setw(26);
            }if(i == 11){
                cout <<setw(25);
            }if(i == 12){
                cout <<setw(30);
            }if(i == 13){
                cout <<setw(28);
            }

            cout <<i+1; //Numbers for rows
            for(int j = 0; j < COL; j++){
                cout <<" " <<c.grid[c.dispG].grid[i][j];
            }
            if(i == 1){
                cout <<" Enemy's Ships:";
            }if(i > 1){
                if(i < 7){
                    cout <<" Ship " <<i-1 <<": " <<c.ship[i-2].shipLtemp <<"/" 
                            <<c.ship[i-2].shipL <<" Hits Remaining";
                }
            }if(i == 10){
                cout <<" Enemy's:";
            }if(i == 11){
                cout <<" Bombs Remaining: " <<c.nbombs;
            }if(i == 12){
                cout <<" Total Hits: " <<c.totHit;
            }if(i == 13){
                cout <<" Total Misses: " <<c.totMiss;
            }
        }
        cout <<endl;
    }
    
}

void getInpt(Player &p, bool &i, bool &end){
    string in;
    char a,b;
    do{
        if(i){
            cout <<"Instructions:" <<endl;
            cout <<"    Enter the letter and number you wish to strike " <<endl;
            cout <<"    Then 'B' to order a bomb strike if desired." <<endl;
            cout <<"    i.e. \"H9\" for a missile or \"H9B\" for a bomb" <<endl;
            cout <<"    Or enter 'Q' to quit the game" <<endl;
            
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
    cout <<endl;
    cout <<"Game End:" <<endl;
    cout <<"    Game Time(sec) - " <<p.time <<endl;
    cout <<"    Bombs Remaining - " <<p.nbombs <<endl;
    cout <<"    Hits - " <<p.totHit <<endl;
    cout <<"    Misses - " <<p.totMiss <<endl;
    cout <<"    Hits per strikes called - " <<p.ratio <<endl;
    cout <<"    Your Initials: ";
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

void gmEnd(Player p, Player c, bool &b){
    short temp1 = 0, temp2 = 0;
    for(int i = 0; i < p.nShips; i++){
        temp1 += p.ship[i].shipLtemp;
        temp2 += c.ship[i].shipLtemp;
        if(temp1 == 0 || temp2 == 0){
            b = true;
        }
    }
}

bool dspMenu(){
    short opt;
    bool a;
    do{
    cout <<setw(27) <<"BATTLESHIP" <<endl <<endl;
    cout <<"Enter the number that corresponds to the option you choose:" <<endl;
    cout <<"    1) Let me place my ships myself" <<endl;
    cout <<"    2) Place and orient my ships automatically" <<endl;
    cin >>opt;
    }while(!(opt == 1 || opt == 2));
    if(opt == 1){
        return a = true;
    }else{
        return a = false;
    }
}

void mkShpG(Player &p, Player c){
    p.ship = new Ship[p.nShips];
    
    for(int i = 0; i < p.nShips; i++){
        switch(i){
            case 0:{
                p.ship[i].shipL = 5;
                break;
            }case 1:{
                p.ship[i].shipL = 4;
                break;
            }case 2:{
                p.ship[i].shipL = 3;
                break;
            }case 3:{
                p.ship[i].shipL = 3;
                break;
            }case 4:{
                p.ship[i].shipL = 2;
                break;
            }
        }
    }
    string in;
    char d;
    for(int i = 0; i < p.nShips; i++){
        cin.ignore();
        p.ship[i].shipLtemp = p.ship[i].shipL;
        prntScrn(p, c);
        cout <<"Enter the column letter followed by the row number in the above table to place the" <<endl; 
        cout <<"initial character of ship " <<i+1 <<" which is of ";
        cout <<p.ship[i].shipL <<" characters." <<endl;

        getline(cin, in);

        stringstream ss(in);
        ss >>d >> p.ship[i].shipY;

        d = toupper(d);
        p.ship[i].shipX = static_cast<int>(d-65)+1;
        do{
            cout <<"Now enter a '0' to orient the ship horizontally or a '1' to orient the ship vertically." <<endl;
            cin >>p.ship[i].ortn;
        }while(!(p.ship[i].ortn == 0 || p.ship[i].ortn == 1));
        p.grid = drwGrid(p);
    }
    
}

void cmpInpt(Player &c, Player p){
    short pRow, pCol, shp, shpL;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(p.grid[p.dispG].grid[i][j] == 'H'){
                pRow = i;
                pCol = j;
                if(){
                    
                }
            }
        }
    }
}