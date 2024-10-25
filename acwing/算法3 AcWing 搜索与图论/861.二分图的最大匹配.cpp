#include<bits/stdc++.h>
using namespace std;

const int N = 510,M = 100010;
int h[N],e[M],ne[M],idx;
int match[N],n1,n2,m;
bool st[N];

void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool find(int x){
	for(int i = h[x];i!=-1;i=ne[i]){
		int j = e[i];
		// 没有访问过
		if(!st[j]){
			st[j] = true;
			// 没有匹配 或者可以匹配其他的
			if(!match[j] || find(match[j])){
				match[j] = x;
				return true;
			}
		} 
	}
	return false;
}

int main(){
	cin>>n1>>n2>>m;
	memset(h,-1,sizeof h);
	while(m--){
		int u,v;
		cin>>u>>v;
		add(u,v);
	}
	
	int res = 0;
	
	for(int i=1;i<=n1;i++){
		// 每次模拟匹配的预定情况都是不一样的 
		// 所以每轮模拟都要初始化
		memset(st,false,sizeof st);
		if(find(i))
			res++; 
	}
	cout<<res;
	return 0;
}
