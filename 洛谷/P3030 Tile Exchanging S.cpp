#include<bits/stdc++.h>
using namespace std;

int n,m,a[11],dp[11][10001];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,54088988,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<=sqrt(j);k++)
				dp[i][j]=min(dp[i][j],dp[i-1][j-k*k]+abs(a[i]-k)*abs(a[i]-k));
	if(dp[n][m]>=54088988)
		cout<<"-1";
	else
		cout<<dp[n][m];
	return 0;
}
