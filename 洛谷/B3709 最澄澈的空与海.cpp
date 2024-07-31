#include<bits/stdc++.h>
using namespace std;

int main(){
	int j=1,n;
	cin>>n;
	for(int i=1;i<=n;i++)
		j*=i;
	cout<<2*(j-n)<<" "<<2*(j-2*n)<<" "<<2;
	return 0;
} 
