#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int a[1000000010];

int main(){
	int n,k;
	long long sum=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==k){
			a[i]=-a[i];
		}
	}
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	cout<<sum;
	return 0;
} 
