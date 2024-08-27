#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		cnt += s[i]-'0';
	}
	cout<<cnt;
}
