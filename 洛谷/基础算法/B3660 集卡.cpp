#include<bits/stdc++.h>
using namespace std;

bool check(long long x){
	if(x==0){
		return 1;
	}
	return 0;
}

int main(){
	int T,n;
	bool ok=0;
	cin>>T;
	while(T--){
		cin>>n;
		bool ok=false;
		for(int i=1,x;i<=n;++i){
			cin>>x;
			if(x==0)
				ok=true;
		}
		if(ok==true)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
