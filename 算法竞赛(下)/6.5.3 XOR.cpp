#include<bits/stdc++.h>
#define N 10100
using namespace std;
typedef long long ll;
int n;
bool zero;
ll a[N];

void Gauss(){
	int i,k=1;
	ll j=(ll)1<<62;
	for(;j;j>>=1){
		
		for(i=k;i<=n;i++)
			if(a[i]&j)
				break;
		if(i>n)
			continue;
		swap(a[i],a[k]);
		for(i=1;i<=n;i++)
			if(i!=k && a[i]&j)
				a[i]^=a[k];
		k++;
	}
	k--;
	if(k!=n)
		zero=1;
	else
		zero=0;
	n=k;
} 

ll Query(ll k){
	ll ans=0;
	if(zero)
		k--;
	if(!k)
		return 0;
	for(int i=n;i;i--){
		if(k&1)
			ans^=a[i];
			k>>=1;
	}
	if(k)
		return -1;
	return ans;
}

int main(){
	int cnt=0;
	int T;
	cin>>T;
	while(T--){
		printf("Case # %d:\n",++cnt);
		cin>>n;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		Gauss();
		int q;
		cin>>q;
		while(q--){
			ll k;
			scanf("%lld",&k);
			printf("%lld\n",Query(k));
		}
	}
}
