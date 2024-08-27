#include<bits/stdc++.h>
using namespace std;

#define pi 3.14159
int main(){
	double a,ans;
	cin>>a;
	ans = 2 * pi * a;
	cout<<fixed<<setprecision(6)<<ans<<'\n';
	ans = pi * a * a;
	cout<<fixed<<setprecision(6)<<ans;
	return 0;
}
