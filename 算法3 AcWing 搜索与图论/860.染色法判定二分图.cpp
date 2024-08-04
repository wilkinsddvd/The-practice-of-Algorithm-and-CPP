#include<bits/stdc++.h>
using namespace std;

const int N = 100010,M = 2*N;
int h[N],e[M],ne[M],idx;
int color[N];
int n,m;

void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
} 

// �ж� u Ⱦ c �Ƿ�Ⱦɫ�ɹ� Ĭ��c Ϊ 1 2 

bool dfs(int u,int c){
	color[u] = c;
	for(int i=h[u];i!=-1;i=ne[i]){
		int j = e[i];
		// δȾɫ
		if(!color[j]){
			// Ⱦɫʧ��
			if(!dfs(j,3-c)) 
				return false; 
		} 
		// Ⱦ��ͬһ����ɫ
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
			// ��Ⱦ1����ɫ
			if(!dfs(i,1)){
				f = false;
				break;
			} 
		}
	}
	cout<<(f?"Yes":"No");
	return 0;
}
