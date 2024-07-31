#include<bits/stdc++.h>
using namespace std;

int main(){
	int m=3,u=3,n=3;
	int a[3][3]={{1,1,1},{1,1,1},{1,1,1}};
	int b[3][3]={1,1,1,1,1,1,1,1,1};
	int c[n][m];
	for(int i=1;i<=m;i++){
		for(int j=1;j<=u;j++){
			for(int k=1;k<=n;k++){
				c[i][j] += a[i][k] * b[k][j];
				cout<<c[i][j]<<endl;
			}
		}
	}
}
