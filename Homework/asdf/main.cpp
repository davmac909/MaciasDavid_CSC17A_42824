#include <iostream>
#include <string>
using namespace std;


int main(){
string name = "john doe"; //or just get string from user...
string in;
for(int i = 0; i < name.size(); i++) {
    name.at(i) = toupper(name.at(i));
}
cout <<"type" <<endl;
cin >>in;
for(int i = 0; i < in.size(); i++) {
    in.at(i) = toupper(in.at(i));
}
cout <<in <<endl;
cout <<name;
	return 0;
}
