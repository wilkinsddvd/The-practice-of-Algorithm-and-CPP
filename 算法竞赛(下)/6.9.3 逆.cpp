#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5;
const int mod = 1e9+7;

ll sum[N],mul[N];
ll fast_pow(ll x,ll y,int m){
	ll res=1;
	while(y){
		if(y&1)
			res*=x,res%=m;
			x=(x*x)%m;
			y>>=1; 
	}
	return res;
}

long long mod_inverse(long long a,long long mod){
	return fast_pow(a,mod-2,mod);
}

void init(){
	sum[1]=0;
	mul[1]=1;
	for(int i=2;i<=N;i++){
		sum[i] = sum[i-1]+i;
		mul[i] = (i*mul[i-1])%mod; 
	} 
}

int main(){
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		if(x==1){
			puts("1");
			continue;
		}
		int k=upper_bound(sum+1,sum+1+N,x)-sum-1;
		int m = x-sum[k];
		ll ans;
		if(k==m){
			ans=mul[k] * mod_inverse(2,mod) % mod *(k+2) % mod;
		}else{
			ans=mul[k+1]*mod_inverse(k-m+1,mod)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
