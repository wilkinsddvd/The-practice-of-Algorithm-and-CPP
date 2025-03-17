#include<iostream>

using namespace std;

int main(){
	int year;
	cout<<"What year was you house built?\n";
	cin>>year;
	char address[80];
	cout<<"What is its street address?\n";
	cin>>address;	
	cout<<"Year built:"<<year<<endl;
	cout<<"Address:"<<address<<endl;
	cout<<"Done!\n";
	return 0;
}
