#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,k,r,c,t,ans1,ans2;
	cin>>a>>b>>k>>r>>c; 
	t = b-a;
	ans1 = t*(k*(r-c));
	cout<<ans1;
	return 0;
}
