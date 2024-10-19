#include<bits/stdc++.h>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int N = 3e5+2;

struct edge{
	int from,to;
	long long w;
	edge(int a,int b,long long c){
		from = a;
		to = b;;
		w = c;
	}
};

vector<edge>e[N];
struct node{
	int id;	long long n_dis;
	node(int b,long long c){
		id = b;
		n_dis = c;
	}
	bool operator<(const node &a)const{
		return n_dis>a.n_dis;
	}
};

int n,m;
int pre[N];

void print_path(int s,int t){
	if(s == t){
		printf("%d",s);
		return;
	}
	print_path(s,pre[t]);
	printf("%d",t);
}

long long dis[N];
bool done[N];

void dijkstra(){
	int s = 1;
	for(int i=1;i<=n;i++){
		dis[i] = INF;
		done[i] = false;
	}  
	dis[s] = 0;
	priority_queue<node>Q;
	Q.push(node(s,dis[s]));
	while(!Q.empty()){
		node u = Q.top();
		Q.pop();
		if(done[u.id])	continue;
		done[u.id] = true;
		for(int i=0;i<e[u.id].size();i++){
			edge y = e[u.id][i];
			if(done[y.to])	continue;
			if(dis[y.to] > y.w + u.n_dis){
				dis[y.to] = y.w + u.n_dis;
				Q.push(node(y.to,dis[y.to]));
				pre[y.to] = u.id;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	e[i].clear();
	while(m--){
		int u,v,w;	cin>>u>>v>>w;
		e[u].push_back(edge(u,v,w));
	}
	dijkstra();
	for(int i=1;i<=n;i++){
		if(dis[i] >= INF)	cout<<"-1";
		else	printf("%lld ",dis[i]);
	}
}
