#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
int olda[N];
int newa[N];

int main(){
	int n;	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>olda[i];
		newa[i] = olda[i];
	}
	sort(olda+1,olda+1+n);
	int cnt = n;
	cnt = unique(olda+1,olda+1+n) - (olda + 1);
	for(int i=1;i<=cnt;i++)
		newa[i] = lower_bound(olda+1,olda+1+n,newa[i]) - olda;
		
	for(int i=1;i<=cnt;i++)	cout<<newa[i]<<" "; 
	cout<<endl<<" "<<"cnt= "<<cnt;
	return 0;
}
 
