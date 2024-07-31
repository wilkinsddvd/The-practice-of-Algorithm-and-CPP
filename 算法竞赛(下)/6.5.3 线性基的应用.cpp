#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M=63;
ll p[M];
bool zero;

void Insert(ll x){
	for(int i=M;i>=0;i--)
		if(x>>i==1)
			if(p[i]==0){
				p[i]=x;
				return;
			}
		else
			x^=p[i];
	zero=true;
} 

ll qmax(){
	ll ans=0;
	for(int i=M;i>=0;i--)
		ans=max(ans,ans^p[i]);
	return ans;
}

int main(){
	ll x;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld",&x),Insert(x); 
	cout<<qmax();
	return 0;
}
