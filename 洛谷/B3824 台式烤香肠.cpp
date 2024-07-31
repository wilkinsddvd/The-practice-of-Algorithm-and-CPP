#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,d,e,f,g,ans,ans1,ans2;
	cin>>a>>b>>c>>d>>e>>f>>g;
	ans1=(g/b)*a*c;
	ans2=(g/e)*d*f;
	if(ans1>ans2){
		cout<<ans1;
	}else{
		cout<<ans2;
	}
	return 0;
} 
