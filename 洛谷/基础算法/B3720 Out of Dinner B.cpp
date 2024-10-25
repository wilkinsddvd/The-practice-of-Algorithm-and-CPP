#include<bits/stdc++.h>
using namespace std;

double check(string s){
	double ans=1;
	if((s[0]=='B' && s[1]=='C') || (s[0]=='C' && s[1]=='B')){
		ans=6;
		return ans;
	}
	if((s[0]=='B' && s[1]!='C') || (s[0]!='C' && s[1]=='B')){
		ans=8;
		return ans;
	}
	if((s[0]=='C' && s[1]!='B') || (s[0]!='C' && s[1]=='B')){
		ans=7;
		return ans;
	}
	return ans;
}

int main(){
	double n,ans=1;
	int result;
	string s;
	cin>>n>>s;
	ans=check(s);
	result=n*ans/10;
	cout<<result;
	return 0;
}
