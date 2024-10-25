#include<bits/stdc++.h> 
using namespace std;

int main(){
	long long x,y,n,ans;
	cin>>x>>y>>n;
	if((x-1) * 10 < y-1){
		ans = n * (x-1);
	}else{
		ans = (n%10) * (x-1);
		ans += (n/10) * (y-1);
	}
	cout<<ans;
	return 0;
}
