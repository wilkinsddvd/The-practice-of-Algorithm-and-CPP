#include<bits/stdc++.h>
using namespace std;

int l,n,a,i,mx,mn;
int main(){
	cin>>l>>n;
	for(i=1;i<=n;i++){
		cin>>a;
		if(a<=l/2){
			mn = max(a,mn);
			mx = max(mx,l-a+1);
		}else{
			mn = max(l-a+1,mn);
			mx = max(mx,a);
		}
	}
	cout<<mn<<' '<<mx;
} 
