#include<bits/stdc++.h>
using namespace std;

int main(){
	double x;
	double a,b;
	cin>>a>>b;
	x = a/b;
	cout<<a<<"/";
	cout<<fixed<<setprecision(1)<<x;
	cout<<"=";
	cout<<fixed<<setprecision(0)<<b;
	return 0;
}
