#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull a[10010];
char s[10010];

ull BKDRhash(char *s){
	ull P = 131,H = 0;
	int n =  strlen(s);
	for(int i=0;i<n;i++)
		H = H * P + s[i] - 'a' + 1;
	while(*s)
		H = H * P +(*s++);
	return H;
} 

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		a[i] = BKDRhash(s);
	}
	int ans = 0;
	sort(a,a+n);
	for(int i=0;i<n;i++)
		if(a[i] != a[i+1])
			ans++;
	cout<<ans;
	
}
