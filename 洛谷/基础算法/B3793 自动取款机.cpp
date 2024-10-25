#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c=0,ans;
	cin>>a>>b;
	c = b-a;
	if(c<0){
		c = abs(c);
		ans = c/100;
		if(c - ans * 100 > 0)
			ans += 1;
			cout<<ans;
			return 0;
		cout<<ans;
		return 0;
	}
	cout<<"0";
	return 0;
} 
