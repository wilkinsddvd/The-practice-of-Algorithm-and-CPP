#include<bits/stdc++.h>
using namespace std;

int a[101],n,cnt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;a[i]!=a[n];i++)
		cnt+=a[i];
	cout<<cnt;
	return 0;
}
