#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100010,M = 2 * N;
int p[N],n,m;
struct Edge{
	int a,b,w;
	
	bool operator < (const Edge & edge)const{ 
		return w < edge.w;
	}
}edges[M];

int find(int x){
	if(p[x] != x) 
		p[x] = find(p[x]);
	return p[x];
} 

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i] = i;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges[i] = {u,v,w};
	}
	sort(edges,edges + m); 
	
	int res = 0,cnt=0;
	// 遍历最短边
	for(int i = 0;i<m;i++){
		int a = edges[i].a,b=edges[i].b,w = edges[i].w;
		// 判断a b 是否在一个集合内
		a = find(a),b = find(b);
		if(a != b){
			res += w;
			cnt++;
			p[a] = b;
		} 
	} 
	if(cnt < n-1) puts("impossible");
	else
		cout<<res;
	
	return 0;
}
