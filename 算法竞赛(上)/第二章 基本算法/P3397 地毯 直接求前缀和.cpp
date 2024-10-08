#include<bits/stdc++.h>
using namespace std;

int D[5000][5000];

int main(){
	int n,m;	cin>>n>>m;
	while(m--){
		int x1,y1,x2,y2;	cin>>x1>>y1>>x2>>y2;
		D[x1][y1] += 1;	D[x2+1][y1] -= 1;
		D[x1][y2+1] -= 1;	D[x2+1][y2+1] += 1;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<n;++j)
			D[i][j+1] += D[i][j];
	for(int j=1;j<=n;++j)
		for(int i=1;i<n;++i)
			D[i+1][j] += D[i][j];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			cout<<D[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
