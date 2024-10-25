#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,d,e,sum1,sum2,ans;
	cin>>a>>b>>c>>d>>e;
	sum1=c*5;
	if(sum1>e){
		ans=sum1+d*20-(b-d)*20;
		if(ans<0){
			ans=0;
		}
		cout<<ans;
		return 0;
	}
	sum1-=(b-d)*20;
	if(sum1<0){
		sum1=0;
	}
	cout<<sum1;
	return 0;
} 
