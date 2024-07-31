#include<cstdio>
#include<algorithm>
#include<cstring>
const int INF=0x3f;
const int N=120;
int Hash[1005],cnt=0;

struct matrix{
	int m[N][N];
};

matrix operator*(const matrix&a, matrix&b){
	matrix c;
	memset(c.m,INF,sizeof c.m);
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			for(int k=1;k<=cnt;k++){
				c.m[i][j] = std::min(c.m[i][j],a.m[i][k]+b.m[k][j]);
			}
		}
	}
	return c;
}

matrix pow_matrix(matrix a,int n){
	matrix ans=a;
	n--;
	while(n){
		if(n&1)
			ans=ans*a;
		a=a*a;
		n>>=1;
	}
	return ans;
}

int main(){
	int n,t,s,e;
	matrix a;
	memset(a.m,INF,sizeof a.m);
	while(t--){
		int u,v,w;
		if(!Hash[u])
			Hash[u]=++cnt;
		if(!Hash[v])
			Hash[v]=++cnt;
		a.m[Hash[u]][Hash[v]] = a.m[Hash[v]][Hash[u]]=w;
	}
	matrix ans = pow_matrix(a,n);
	printf("%d",ans.m[Hash[s]][Hash[e]]);
	return 0;
}

