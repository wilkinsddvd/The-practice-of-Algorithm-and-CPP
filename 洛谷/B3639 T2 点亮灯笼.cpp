#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n]={0};
	while(m--){
		int x;
		cin>>x;
		if(x>1 && x<n){
			a[x-1] = 1-a[x-1];
			a[x] = 1-a[x];
			a[x-2] = 1-a[x-2];
		}else if(x==1){
			a[x-1]=1-a[x-1];
			a[x]=1-a[x];
			a[n-1]=1-a[n-1];
		}else if(x==n){
			a[x-2]=1-a[x-2];
			a[x-1]=1-a[x-1];
			a[0]=1-a[0]; 
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
