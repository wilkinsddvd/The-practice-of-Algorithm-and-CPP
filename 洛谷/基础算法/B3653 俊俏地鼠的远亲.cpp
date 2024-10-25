#include<bits/stdc++.h>
using namespace std;

int n,m;
long long b[57][57];
int ans[57][57];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int x=1;x<=n;x++){
				for(int y=1;y<=m;y++){
					if(b[x][y] == b[i][j]){
						ans[i][j]=max(ans[i][j],(i-x)*(i-x)+(j-y)*(j-y));
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
