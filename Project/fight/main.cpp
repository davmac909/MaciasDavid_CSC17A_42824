#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include "PlayerOne.h"

using namespace std;


void playerChoice(int num, PlayerOne *you);
void compPlayer(PlayerOne *you);
bool coinFlip();
void attack(PlayerOne *opp);
void oppAttack(PlayerOne *you);

int main(int argc, char** argv) {
	PlayerOne leslie;
        //int health=50;
	//PlayerOne *leslie=leslie(health);
	char c;
        //char ch;
        int num;
        
        
	cout << "Welcome to Leslie's Awesome Battle " << endl;
        cout << "Each game costs 25 cents to play, enter amount that coresponds to how many times you would like to play" << endl;
        cout << "Example: 25 = 1 game, 50 = 2 games, 75 = 3 games, etc.. " << endl;
                cin >> num;
        cout << "You entered " << num << " you may play up to " << (num/25) << " times" << endl;
        cout << "Enter your name " << endl;
        cin >> leslie.name;
        cout << "Welcome " << leslie.name << endl;
        leslie.lives=num/25;
        leslie.level=1;
        playerChoice(num, &leslie);
        while(leslie.lives > 0 ){
	cout << "Press C to continue " << endl;
	cin >> c;
        cout <<"**************************************" << endl;
	
	if (c == 'c')
	{
		
		compPlayer(&leslie);
                leslie.health=50;
                leslie.health2=50;
                //int tries;
                //tries=&num/25;
                
                if (coinFlip()==true)
                {
                    
                    do{ 
                        
                        
                        attack(&leslie);
                        oppAttack(&leslie);
                    }while((leslie.health>0)||(leslie.health2>0));
                    if (leslie.health<=0)
                        {
                            leslie.lives-=1;
                            cout << "Sorry you lost a life " << leslie.lives << endl;
                            cout <<"**************************************" << endl;
                            cout <<"**************************************" << endl;
                        }
                    else  if (leslie.health2<=0)
                        {
                            cout << "YOU WIN!" << endl;
                            leslie.level+=1;
                            cout << "Congratulations, you level up " << leslie.level << endl;
                            cout <<"**************************************" << endl;
                            cout <<"**************************************" << endl;
                        }
                }
                else
                {
                    do {
                              
                        oppAttack(&leslie);
                        attack(&leslie);
                   }while((leslie.health>0)||(leslie.health2>0));
                    if (leslie.health<=0)
                        {
                         leslie.lives-=1;
                         cout << "Sorry you lost a life " << leslie.lives << endl;
                         cout <<"**************************************" << endl;
                         cout <<"**************************************" << endl;                              
                        }
                    else if (leslie.health2<=0)
                     {
                            cout << "YOU WIN!" << endl;
                            leslie.level+=1;
                            cout << "Congratulations you level up " << leslie.level << endl;      
                            cout <<"**************************************" << endl;
                            cout <<"**************************************" << endl;                            
                     }
                    
                 } 
                cout << leslie.name << "'s final stats " << endl;
                cout << "Level: " << leslie.level << endl;
                cout << "Lives : " << leslie.lives << endl;
              
                }   
	else
	{
		cout << "Invalid entry, Goodbye " << endl;
	}
        }
    return 0;

}

void playerChoice(int num, PlayerOne *you)
{
	char choice;
        cout <<"**************************************" << endl;
        cout <<"**************************************" << endl;
        cout <<"**************************************" << endl;
	cout << "Choose your player " << endl;
	cout << "1. Night Wing" << endl;
	cout << "2. Batman " << endl;
	cout << "3. Superman" << endl;
	cout << "4. Spiderman " << endl;
	cin >> choice;
        cout <<"**************************************" << endl;
        cout <<"**************************************" << endl;
        cout <<"**************************************" << endl;
	if (choice == '1')
	{
		cout << "You chose Night Wing" << endl;
	}
	else if (choice == '2')
	{
		cout << "You chose Batman" << endl;
	}
	else if (choice == '3')
	{
	cout << "You chose Superman" << endl;
	}
        else if (choice =='4')
	{
		cout << "You chose Spiderman" << endl;

	}
        else 
        {
            cout << "Invalid entry!" << endl;
        }
       you->health=50;
        
	cout << "Level: " << you->level << endl;
	cout << "Health: " << you->health << endl;
	cout << "Lives: " << you->lives << endl;
        cout <<"**************************************" << endl;
        cout <<"**************************************" << endl;
	
}
void compPlayer(PlayerOne *opp)
{
	srand(time(NULL));
	string comPlayer[4] = { "Night Wing", "Batman", "Superman", "Spiderman" };
	int ran = rand() % 4;
	cout << "Your opponent is " << comPlayer[ran] << endl;
	cout << comPlayer[ran] << " stats" << endl;
        opp->health2=50;
	cout << "Health : " << opp->health2 << endl;
        cout <<"**************************************" << endl;
        cout <<"**************************************" << endl;
}

bool coinFlip()
{
	char flip;
	char coin;
	cout << "Pick heads or tails to see who will go first " << endl;
	cin >> flip;
	if (rand() % 2 == 0)
		coin = 'H';
	else
		coin = 'T';
	if (toupper(flip) == coin)
	{
		cout << "You chose right, you start" << endl;
                cout <<"**************************************" << endl;
                cout <<"**************************************" << endl;
                
		return true;
	}
	else
	{
		cout << "You chose wrong, sorry" << endl;
                cout <<"**************************************" << endl;
                cout <<"**************************************" << endl;
  
		return false;
        }

}
void attack(PlayerOne *opp)
{
	char att;
	srand(time(NULL));
	cout << "Choice of attack " << endl;
	cout << "1. Punch " << endl;
	cout << "2. Kick " << endl;
	cout << "3. Special " << endl;
	cin >> att;
      //  opp->health=50;
      
	if (att == '1')
	{
		cout << "You chose punch " << endl;
		if (rand() % 6 != 0)
		{
			cout << "Your punch landed!" << endl;
			opp->health2 -=10;
			cout << "Opponent's Health : " << opp->health2 << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
                       
		}
		else
		{
			cout << "Your punch did not land " << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
                        
		}
	}
	else if (att == '2')
	{
		cout << "You chose kick " << endl;
		if (rand() % 4 != 0)
		{
			cout << "Your kick landed!" << endl;
			opp->health2 -= 15;
			cout << "Opponent's Health : " << opp->health << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
		else
		{
			cout << "Your punch did not land " << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
	}
	else 
	{
		cout << "You chose special attack " << endl;
		if (rand() % 2 != 0)
		{
			cout << "Your attack landed!" << endl;
			opp->health2 -= 20;
			cout << "Opponent's Health : " << opp->health2 << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
		else
		{
			cout << "Your attack did not land " << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
	}
        
}
void oppAttack(PlayerOne *you)
{
	srand(time(NULL));
	char attack[3] = { '1', '2', '3' };
	int index = rand() % 3; 
	//cout << attack[index] << ". ";
      //you->health=50;
     
        if (attack[index] == '1')
	{
		cout << "Your opponent chose punch" << endl;
		if (rand() % 6 != 0)
		{
			cout << "Punch landed!" << endl;
			you->health -= 10;
			cout << "Your Health : " << you->health << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
		else
		{
			cout << "Punch did not land " << you->health << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
	}
	else if (attack[index] == '2')
	{
		cout << "Your opponent chose kick" << endl;
		if (rand() % 4 != 0)
		{
			cout << "Kick landed!" << endl;
			you->health2 -= 15;
			cout << "Your Health : " << you->health << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
		else
		{
			cout << "Kick did not land " << you->health << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
                       
		}
	}
	else
	{
		cout << "Your opponent chose special attack" << endl;
		if (rand() % 2 != 0)
		{
			cout << "Attack landed!" << endl;
			you->health -= 20;
			cout << "Your Health : " << you->health << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
		else
		{
			cout << "Attack did not land " << you->health << endl;
                        cout <<"**************************************" << endl;
                        cout <<"**************************************" << endl;
		}
	}
     
}