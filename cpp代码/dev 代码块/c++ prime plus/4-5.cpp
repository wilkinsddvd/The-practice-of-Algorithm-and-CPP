#include<iostream>

using namespace std;

const int ArSize=20;

int main(){
	char name[ArSize],dessert[ArSize];
	
	cout<<"Enter your name:\n";
	cin.get(name,ArSize).get();
	cout<<"Enter your favorite.dessert:\n";
	cin.get(dessert,ArSize).get();
	cout<<"I have some delicious "<<dessert<<" for you, "<<name<<".\n";
	return 0;	
}		
