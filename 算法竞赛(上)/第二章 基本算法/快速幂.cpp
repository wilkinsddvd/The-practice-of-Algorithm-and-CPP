#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fastPow(ll a,ll n,ll m){
	if(n == 0)	return 1;
	if(n == 1)	return a;
	ll temp = fastPow(a,n/2,m);
	if(n % 2 == 1)	return temp % m * temp % m * a % m;
	else	return temp * temp % m;
}

int main(){
	ll a,n,m;
	cin>>a>>n>>m;
	cout<<a<<"^"<<n<<" mod "<<m<<"="<<fastPow(a,n,m);
	return 0;
}
