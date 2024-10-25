#include<iostream>
#include<cstring>

using namespace std;

const int N = 10010;

int h[N],e[N],ne[N],w[N],idx;
int q[N], hh, tt = -1;
int d[N],cnt[N];
bool st[N];
int n,m;

void add(int a,int b,int c){
	e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
}

// 如果存在负环 则返回true 否则返回false

bool spfa(){
	// 不需要初始化d数组
	// 原理:
	//      如果某条最短路径上有n个点(除了自己)
	//      那么加上自己之后一共有n+1个点
	//      由抽屉原理(鸽巢原理) 一定有两个点相同
	//      所以存在环 
	for(int i=1;i<=n;i++){
		q[++tt] = i;
		st[i] = true;
	} 
	
	while(hh <= tt){
		int t = q[hh++];
		st[t] = false;
		for(int i=h[t];i!=-1;i=ne[i]){
			int j = e[i];
			if(d[j] > d[t] + w[i]){
				d[j] = d[t] + w[i];
				cnt[j] = cnt[t] + 1;
				
				if(cnt[j] >= n) return true;
				if(!st[j]){
					q[++tt] = j;
					st[j] = true;
				}
			}
		}
	} 
	return false;
} 

int main(){
	cin>>n>>m;
	memset(h,-1,sizeof h);
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c); 
	}
	if(spfa()) puts("Yes");
	else
		puts("No");
		
	return 0; 
}

