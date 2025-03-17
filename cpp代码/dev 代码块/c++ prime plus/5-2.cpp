#include<iostream>
using namespace std;

int main(){
	cout<<"Enter the starting countdown value: ";
	int limit;
	cin>>limit;
	for(int i=limit;i;i--){
		cout<<"i = "<<i<<"\n";
	}
	return 0;
}
