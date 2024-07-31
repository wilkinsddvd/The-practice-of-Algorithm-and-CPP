#include<bits/stdc++.h>
using namespace std;
int a[5010];

int main(){
	long long n,k,cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
