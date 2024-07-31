#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=20000010;
typedef long long ll;
const ll mod=1000000007;
ll T,n,m,p,cur,pri[maxn],f[maxn],sum[maxn];
bool tf[maxn];
ll calc(ll n,ll m)
{
	ll ret=0;
	for(ll i=1,j;i<=min(n,m);i=j+1)
	{
		j=min(n/(n/i),m/(m/i));
		ret=(ret+(n/i)*(m/i)%mod*((sum[j]-sum[i-1]+mod)%mod)%mod)%mod;
	}
	return ret;
}
int main()
{
	f[1]=1;
	for(ll i=2;i<=20000000;i++)
	{
		if(!tf[i]){pri[++cur]=i;f[i]=(i*i%mod-1+mod)%mod;}
		for(ll j=1;j<=cur&&i<=20000000/pri[j];j++)
		{
			tf[i*pri[j]]=true;
			if(i%pri[j]==0){f[i*pri[j]]=f[i]*pri[j]%mod*pri[j]%mod;break;}
			else f[i*pri[j]]=f[i]*f[pri[j]]%mod;
		}
	}
	for(ll i=1;i<=20000000;i++)sum[i]=(sum[i-1]+f[i])%mod;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&p);
		printf("%lld\n",(p*calc(n,m)%mod+m*calc(n,p)%mod+n*calc(m,p)%mod)%mod);
	}
	return 0;
}
