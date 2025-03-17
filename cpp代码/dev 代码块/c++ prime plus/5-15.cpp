#include<iostream>

using namespace std;

int main(){
	int n;
	cout << "Enter number in the range 1-10 to find ";
	cout << "my favorite number\n";
	do{
		cin>>n;
	}while(n != 5);
	cout << "Yes, 5 is my favorite.\n";
	return 0; 
}
