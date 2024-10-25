#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int cnt=0;
	cin>>s;
	for(int i=1;i<=s.size();i++){
		if(s[i]=='l' && s[i+1]=='u' && s[i+2]=='o' && s[i+3]=='g' && s[i+4]=='u'){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
