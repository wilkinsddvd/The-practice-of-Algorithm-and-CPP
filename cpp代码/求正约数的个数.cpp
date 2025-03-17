#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int factor[N],cnt;
int main(){
	int n;
	cin>>n;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			factor[++cnt]=i;
			if(i!=n/i)
				factor[++cnt]=n/i;
		}
	}
	sort(factor+1,factor+cnt+1);
	for(int i=1;i<=cnt;i++){
		cout<<factor[i];
	}
	return 0;
} 
