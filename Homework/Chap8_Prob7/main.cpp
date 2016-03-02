#include <iostream>
#include <string>
using namespace std;

void selectionSort(string names[], int size);
int binarySearch(string names[], int size, string value);
void upperCase(string name[], int size);


int main()
{
	const int NUM_NAMES = 20;

	string names[NUM_NAMES] = { "Collins, Bill","Smith, Bart", "Allen, Jim",
                                    "Griffen, Jim", "Stamey, Marty", "Rose, Geri",
                                    "Taylor, Terri", "Johnson, Jill",
                                    "Allison, Jeff", "Loony, Joe", "Wolfe, Bill",
                                    "James, Jean", "Weaver, Jim", "Pore, Bob",
                                    "Rutherford, Greg", "Javens, Renee",
                                    "Harrison, Rose", "Setzer, Cathy",
                                    "Pike, Gordon", "Holland, Beth" };
	string proName;
	int search;
        upperCase(names, NUM_NAMES);
	selectionSort(names, NUM_NAMES);


	cout << "Enter name :" << endl;
	getline(cin, proName);
        for(int i = 0; i< proName.size(); i++){
            proName.at(i) = toupper(proName.at(i));
        }
	search = binarySearch(names, NUM_NAMES, proName);

	if (search == -1)
		cout << "Invalid entry" << endl;
	else 
		cout << "the name entered is " << search << endl;

	return 0;
}
void selectionSort(string names[], int size){
	int minIndex;
	//char name;
	string minValue;
        
        cout <<"Unsorted Names List: " <<endl;
        for(int i = 0; i < size; i++){
            cout << i <<" " <<names[i] <<endl;
        }
        cout <<endl;
	for (int startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = names[startScan];
		for (int i = startScan + 1; i < size;i++)
			if (names[i]<minValue)
			{
				minValue = names[i];
				minIndex = i;
			}
                names[minIndex] = names[startScan];
	names[startScan] = minValue;
	}
	
	cout <<"Sorted Names List: " <<endl;
        for(int i = 0; i < size; i++){
            cout << i <<" " <<names[i] <<endl;
        }
        cout <<endl;

}
int binarySearch(string names[], int size, string value)
{
	int first = 0, 
		last = size - 1, 
		middle, 
		position = -1;
	bool found = false;

	while (!found&& first <= last)
	{
		middle = (first + last) / 2;
		if (names[middle] == value)
		{
			found = true;
			position = middle;
		}
		else  if (names[middle] > value)
			last = middle - 1;
		else
			first = middle + 1;
	}


	return position;

}
void upperCase(string name[], int size){
    for(int i = 0; i < size; i++){
        int sz = name[i].size();
        for(int j = 0; j < sz; j++){
            name[i].at(j) = toupper(name[i].at(j));
        }
    }
}