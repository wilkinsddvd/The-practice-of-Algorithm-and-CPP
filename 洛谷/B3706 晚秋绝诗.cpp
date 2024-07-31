#include<bits/stdc++.h>
using namespace std;

int main(){
	long long x,y,z;
	long long ans;
	double c;
	cin>>x>>z>>c;
	y = x-2*z;
	x = x-z;
	ans = ceil(y/c);
	cout<<ans;
	return 0;
}
