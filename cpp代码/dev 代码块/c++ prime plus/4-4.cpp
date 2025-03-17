#include<iostream>

using namespace std;

int main(){
	const int ArSize=20;
	char name[ArSize],dessert[ArSize];
	
	cout<<"Enter your name:\n";
	cin.getline(name,ArSize);
	cout<<"Enter you favorite dessert:\n";
	cin.getline(dessert,ArSize);
	cout<<"I have some delicious "<<dessert<<" for you,"<<name<<".\n";
	return 0; 
}
