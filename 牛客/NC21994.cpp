#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d,ans;
	cin>>a>>b>>c>>d;
	ans = c*60+d - (a*60+b);
	cout<<ans;
	return 0; 
} 
