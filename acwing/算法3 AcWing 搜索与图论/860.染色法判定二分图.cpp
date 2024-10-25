#include<bits/stdc++.h>
using namespace std;

const int N = 100010,M = 2*N;
int h[N],e[M],ne[M],idx;
int color[N];
int n,m;

void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
} 

// 判断 u 染 c 是否染色成功 默认c 为 1 2 

bool dfs(int u,int c){
	color[u] = c;
	for(int i=h[u];i!=-1;i=ne[i]){
		int j = e[i];
		// 未染色
		if(!color[j]){
			// 染色失败
			if(!dfs(j,3-c)) 
				return false; 
		} 
		// 染了同一种颜色
		else if(color[j] == c) 
			return false; 
	}
	return true;
} 

int main(){
	cin>>n>>m;
	memset(h,-1,sizeof h);
	
	while(m--){
		int u,v;
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	bool f = true;
	
	for(int i=1;i<=n;i++){
		if(!color[i]){
			// 先染1号颜色
			if(!dfs(i,1)){
				f = false;
				break;
			} 
		}
	}
	cout<<(f?"Yes":"No");
	return 0;
}
