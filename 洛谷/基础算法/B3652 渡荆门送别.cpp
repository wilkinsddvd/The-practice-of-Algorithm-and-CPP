#include<bits/stdc++.h>
using namespace std;

int n;
long long a[1000007];
long long mx = -1,mn = 1e18+1;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx = max(mx,a[i]);
		mn = min(mn,a[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<mx-a[i]<<' ';
	}
	cout<<'\n';
	for(int i=1;i<=n;i++){
		cout<<a[i]-mn<<' ';
	}
	cout<<'\n';
	return 0;
}
