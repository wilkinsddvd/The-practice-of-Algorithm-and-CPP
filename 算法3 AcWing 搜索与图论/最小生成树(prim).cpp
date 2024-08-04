#include<bits/stdc++.h>
using namespace std;

const int N = 510, inf = 0x3f3f3f3f;
int g[N][N], d[N];
bool st[N];
int n,m;

int prim(){
	memset(d,0x3f,sizeof d);
	int res = 0;
	
	for(int i=0;i<n;i++){
		int t = -1;
		for(int j=1;j<=n;j++)
			if(!st[j] && (t  == -1 || d[t] > d[j])) t = j;
	
		// 如果不是第一个点 并且找到的最小点的距离为inf 则不构成最小生成树
		
		if(i && d[t] == inf) return inf;
		
		// 如果不是第一个点 d[t]表示当前点与某一点连线的长度
		
		if(i) res += d[t];
		
		// 先加上 再更新 否则 t=j 时 自环更新长度 
		for(int j=1;j<=n;j++) d[j] = min(d[j],g[t][j]);
		st[t] = true; 
	}
	return  res;
}

int main(){
	cin>>n>>m;
	memset(g,0x3f,sizeof g);
	
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b] = g[b][a] = min(g[a][b],c);
	}
	int t = prim();
	
	if(t == inf) 
		puts("impossible");
	else
		cout<<t<<endl;
	return 0;
}
