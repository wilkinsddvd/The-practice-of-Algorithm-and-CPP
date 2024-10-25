#include<bits/stdc++.h>
using namespace std;

int main(){
	char a,b;
	double n;
	cin>>n>>a>>b;
	if((a=='B' && b=='C') || (a=='C' && b=='B')){
		n*=0.6;
		cout<<n;
		return 0;
	}
	if((a=='B' && b!='C') || (a!='C' && b=='B')) {
		n*=0.8;
		cout<<n;
		return 0;
	}
	if((a=='C' && b!='B') && (a!='B' && b=='C')){
		n*=0.7;
		cout<<n;
		return 0;
	}
	cout<<n;
	return 0;
}
