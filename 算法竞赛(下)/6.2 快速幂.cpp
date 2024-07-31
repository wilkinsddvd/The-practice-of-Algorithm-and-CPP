#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll fastPow(ll a,ll n,ll mod){
	ll ans=1;
	a%=mod;
	while(n){
		if(n&1){
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		n>>=1;
	}
	return ans;
}

int main(){
	ll a=5;
	ll b=9;
	ll c=4;
	cout<<fastPow(a,b,c);
}
