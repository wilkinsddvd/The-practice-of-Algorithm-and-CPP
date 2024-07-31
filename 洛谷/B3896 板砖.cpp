#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,a,k,b,sum1,sum2,ans1,ans2;
	cin>>n>>a>>k>>b;
	sum1=a*k;
	if(b<sum1){
		ans1=(n/k)*b;
		sum2=n-(n/k)*k;
		if(sum2*a<b){
			ans1+=sum2*a;
		}else{
			ans1+=b;
		}
	}else{
		cout<<"-1";
	}
	cout<<ans1;
	return 0;
} 
