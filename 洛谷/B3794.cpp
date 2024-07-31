#include<bits/stdc++.h>
#define pi 3.1415926535
using namespace std;

int main(){
	double a,b,c,ans;
	cin>>a>>b>>c;
	ans = ((a+c)*(b+c) - c*c + (pi * c * c)/4) / 10000;
	cout<<fixed<<setprecision(3)<<ans;
	return 0;
}
