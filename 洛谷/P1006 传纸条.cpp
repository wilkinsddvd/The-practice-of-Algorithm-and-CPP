#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream> 
using namespace std;

int f[110][60][60];
int a[60][60];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	f[1][1][1] = a[1][1];
	for(int p=2;p<=n+m-1;p++)
		for(int i=1;i<=n && i<=p;i++)
			for(int j=1;j<=n && j<=p;j++){
				if(i==1 && j==1) continue;
				f[p][i][j] = max(max(f[p-1][i][j],f[p-1][i-1][j]),max(f[p-1][i][j-1],f[p-1][i-1][j-1])); 
				f[p][i][j] += i == j ? a[i][p-i+1]:a[i][p-i+1]+a[j][p-j+1];
			}
			cout<<f[n+m-1][n][n];
			return 0;
} 
