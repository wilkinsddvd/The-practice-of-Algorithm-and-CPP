#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
const int N = 5e5 + 10;
char s[N],t[N];
int n,PP=131;
long long ans;
ull p[N],f[N],g[N];

void bin_search(int x){
	int L = 0,R = min(x,n-x);
	while(L<R){
		int mid = (L+R+1) >> 1;
		if((ull)(f[x] - f[x-mid] * p[mid]) == (ull)(g[x+1] - g[x+1+mid] * p[mid]))
			L = mid;
		else
			R = mid-1;
	}
	ans += L; 
} 

int main(){
	cin>>n;
	cin>>s+1;
	p[0] = 1;
	for(int i=1;i<=n;i++)
		s[i] == '1' ? t[i] = '0' : t[i] = '1';
	for(int i=1;i<=n;i++)
		p[i] = p[i-1] * PP;
	for(int i=1;i<=n;i++)
		f[i] = f[i-1] * PP + s[i];
	for(int i=n;i>=1;i--)
		g[i] = g[i+1] * PP + t[i];
	for(int i=1;i<n;i++)
		bin_search(i);
	printf("%lld\n",ans);	
	return 0;
}
