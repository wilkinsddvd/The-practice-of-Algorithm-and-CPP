#include<bits/stdc++.h>
using namespace std;

int a[1005][1005];
int b[1005];
int c[1005];
int n1=1,m1=1;
int main(){
	int n,m,cnt=0;
	cin>>n>>m;
	a[n][m]={1};
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];	
			if(a[i][j]>=3){
				cnt++; 
				i=b[n1];
				n1++;
				j=c[m1];
				m1++;				
			}
		}
	}
	int x;
	cin>>x;
	while(x--){
		int a1,a2,b1,b2,temp;
		cin>>a1>>a2>>b1>>b2;
		temp = a[a1][a2]; 
		a[a1][a2] = a[b1][b2];
		a[b1][b2] = temp;
	} 
	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			cout<<b[n]<<" "<<c[m];
		}
	}
	return 0;
}
