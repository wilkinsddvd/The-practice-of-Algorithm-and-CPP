#include<bits/stdc++.h>
using namespace std;

int n,m;
long long dis[2010];
struct P{
	int x,y,z;
}a[2010];

int main(){
	scanf("%d%d",&n,&m);
	bool flag=1;
	for(register int i=1;i<=n;++i)
		dis[i]=1e18;
	dis[1]=0;
	for(register int i=1;i<=m;++i)
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	for(register int i=1;i<=n;++i){
		flag=1;
		for(register int j=1;j<=m;++j)
			if(dis[a[j].y] > dis[a[j].x] + a[j].z) 
				flag=0,dis[a[j].y]=  dis[a[j].x] +a[j].z;
		if(flag)
			break;
	}
	for(register int i=1;i<=n;++i)
		printf("%lld ",dis[i]==1e18 ? -1 : dis[i]);
} 
