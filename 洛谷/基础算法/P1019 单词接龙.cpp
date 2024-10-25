#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int n;
string tr[30];
int yc[30][30];
int vis[30];

int mt(int x,int y){
	bool pp = 1;
	int ky=0;
	for(int k=tr[x].size()-1;k>=0;k--){
		for(int kx=k;kx<tr[x].size();kx++){
			if(tr[x][kx] != tr[y][ky++]){
				pp = 0;
				break;
			}
		}
		if(pp==1){
			return tr[x].size()-k;
		}
		ky = 0;
		pp = 1;
	}
	return 0;
} 

char ch;
int ans=-1;
int an=0;

void dfs(int p){
	bool jx=0;
	for(int j=1;j<=n;j++){
		if(vis[j]>=2)
			continue;
		if(yc[p][j]==0)
			continue;
		if(yc[p][j]==tr[p].size() || yc[p][j]==tr[j].size())
			continue;
		an += tr[j].size()-yc[p][j];
		vis[j]++;
		jx=1;
		dfs(j);
		an -= tr[j].size()-yc[p][j];
		vis[j]--;
	}
	if(jx==0){
		ans = max(ans,an);
	}
	return;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tr[i];
	}
	cin>>ch;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			yc[i][j] = mt(i,j);
		}
	}
	for(int i=1;i<=n;i++){
		if(tr[i][0]==ch){
			vis[i]++;
			an=tr[i].size();
			dfs(i);
			vis[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
