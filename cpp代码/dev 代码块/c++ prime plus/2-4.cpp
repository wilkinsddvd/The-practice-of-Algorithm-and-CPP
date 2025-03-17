#include<iostream>
#include<cmath>

using namespace std;

int main(){
	double area,side;
	cout<<"Enter the floor area,in square feet,of your home:";
	cin>>area;
	side = sqrt(area);
	cout<<"That's the equivalent of a square "<<side<<" feet on the side."<<endl;
	cout<<"How fascinating!"<<endl;
	return 0;
} 
