#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N],D[N];

int main(){
	int n;
	while(~scanf("%d",&n)){
		memset(a,0,sizeof(a));	memset(D,0,sizeof(D));
		for(int i=1;i<=n;i++){
			int L,R;	cin>>L>>R;
			D[L]++;	D[R+1]--; 
		}
		for(int i=1;i<=n;i++){
			a[i] = a[i-1] + D[i];
			if(i != n)	cout<<a[i]<<" ";
			else	cout<<a[i]<<endl;
		}
	}
	return 0;
}
