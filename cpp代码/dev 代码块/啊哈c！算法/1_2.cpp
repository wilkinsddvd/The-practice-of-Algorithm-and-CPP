#include<bits/stdc++.h>
using namespace std;

int main(){
	int book[1001],i,j,t,n;
	for(i=0;i<=1000;i++)
		book[i] = 0;
	
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>t;
		book[t]++;
	}
	
	for(i=1000;i>=0;i--)
		for(j=1;j<=book[i];j++)
			cout<<i<<" ";
		
	getchar(); getchar();
	return 0;
}
