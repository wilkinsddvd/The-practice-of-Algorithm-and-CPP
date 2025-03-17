#include<iostream>
using namespace std;

void simon(int);

void simon(int n){
	cout<<"Simon says touch your toes "<<n<<" times."<<endl;
}

int main(){
	simon(3);
	int count;
	cout<<"Pick an integer:"<<endl;3 
	cin>>count;
	simon(count);
	cout<<"Done!"<<endl;
	return 0;
}
