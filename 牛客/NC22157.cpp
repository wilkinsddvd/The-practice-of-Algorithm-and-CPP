#include<bits/stdc++.h>
using namespace std;

int main(){
	double cnt = 0,n;
	cin>>n;
	for(double i=1;i<=n;i++){
		cnt += 1/i;
	}
	cout<<fixed<<setprecision(6)<<cnt;
	return 0;
}
