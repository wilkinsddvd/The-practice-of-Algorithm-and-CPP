#include<iostream>
using namespace std;

void saddlePoint(int**A,int n,int m)
{
	int row_min[n],col_max[m];
	int i,j;
	for(i=1;i<=n;i++)
		row_min[i]=A[i][j];
	for(j=1;j<=m;j++)
		col_max[j] = A[0][j];
		
	for(i=1;i<=n;i++)
		for(j=1;j<m;j++)
	{
		if(A[i][j]<row_min[i]) row_min[i] = A[i][j];
		if(A[i][j]>col_max[j]) col_max[i] = A[i][j]; 
	}
	
	int flag = 0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
	{
		if(A[i][j] == row_min[i] && A[i][j] == col_max[j])
		{
			flag ++;
			cout<<A[i][j]<<' '<<i<<' '<<j<<endl;
		}	
	}
	if(flag ==0) cout<<"No answer";
}

int main()
{
	int n,m;
	cin>>n>>m;
	int** arr = new int*[n+1];
	for(int i = 0;i <= n + 1;++i)
		arr[i] = new int[m+1];
	
	for(int i = 1; i <= n ; ++i)
		for(int j = 1; j <= m; ++j )
			cin>>arr[i][j];		
	saddlePoint(arr,n,m);
	return 0;
}
