#include<iostream>
#include<climits>

#define ZERO 0

using namespace std;

int main(){
	short sam=SHRT_MAX;
	unsigned short sue = sam;
	
	cout<<"Sam has "<<sam<<" dollars and Sue has "<<sue<<" dollars deposited."<<endl;
	cout<<"Add $1 from each account."<<endl<<"Now";

	sam += 1;
	sue += 1;
	
	cout<<"Sam has "<<sam<<" dollars and Sue has "<<sue<<" dollars deposited."<<endl;
	cout<<"\nPoor Sam!"<<endl<<"Now";
	
	sam=ZERO;
	sue=ZERO;
	
	
	cout<<"Sam has "<<sam<<" dollars and Sue has "<<sue<<" dollars deposited."<<endl;
	cout<<"Take $1 from each account."<<endl<<"Now";
	
	sam -= 1;
	sue -= 1;
	cout<<"Sam has "<<sam<<" dollars and Sue has "<<sue<<" dollars deposited."<<endl<<"Lucky Sue!"<<endl;
	return 0; 
}


