#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,ans;
	char d;
	cin>>a>>b>>c>>d;
	ans=a*60*60 + b*60 + c;
	if(d=='P'){
		ans+=12*60*60; 
	}
	cout<<ans;
	return 0;
}
