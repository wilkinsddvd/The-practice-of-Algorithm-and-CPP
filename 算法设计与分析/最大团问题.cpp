#include<bits/stdc++.h>
using namespace std;

#define maxm 55

int g[maxm][maxm];
int vis[maxm];
int cnt[maxm];
int ans,n;

bool dfs(int cur,int num){
	for(int i=cur+1;i<=n;i++){
		if(cnt[i] + num <= ans)
			return 0;
		if(g[cur][i]){
			int ok = 1;
			for(int j=0;j<num;j++)
				if(!g[i][vis[j]]){
					ok = 0;
					break;
				}
			if(ok){
				vis[num] = i;
				if(dfs(i,num+1))
					return 1;
			}
		} 
	}
	ans = max(ans,num);
	return (ans == max(num,ans) ? 0 : 1);
}


void maxclique(){
	for(int i=n;i>0;i--){
		vis[0] = i;
		dfs(i,1);
		cnt[i] = ans;
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			g[j][i] = g[i][j];
		}
	maxclique();
	cout<<cnt[1];
	return 0;
}
