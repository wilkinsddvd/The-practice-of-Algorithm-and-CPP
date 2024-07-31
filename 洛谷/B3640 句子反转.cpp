#include<bits/stdc++.h>
using namespace std;

#define long long ll

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	string s;
	getline(cin,s);
	reverse(s.begin(), s.end());
	
	for(int i=0;i<s.size()-1;i++){
		if(s[i] <= 'z' && s[i] >='a')
			s[i] = s[i] - 32;
		else if(s[i] <= 'Z' && s[i] >='A')
			s[i] = s[i] + 32;
	}
	for(int i=0;i<s.size()-1;i++){
		if(s[i] == ' ' && !(s[i-1] >= '0' && s[i-1] <= '9')){
			if(s.rfind(' ',i-1)!= s.npos){
				ll flag = s.rfind(' ',i-1);
				string mid = s.substr(flag+1, i-flag-1);
				reverse(mid.begin(), mid.end());
				cout<<mid<<" ";
				continue;
			}
			else{
				string mid = s.substr(0,i);
				reverse(mid.begin(), mid.end());
				cout<<mid<<" ";
				continue;
			}
		}
		else if(s[i] >= '0' && s[i] <= '9')
			cout<<s[i];
		else if(s[i] == ' ')
			cout<<" ";
		if(i == s.size()-1 && !(s[i] <= '9' && s[i] >= '0')){
			ll flag = 0;
			if(s.rfind(' ',i-1)!= s.npos)
				flag = s.rfind(' ',i-1);
			else
				flag = 0;
			if(flag != 0){
				string mid = s.substr(flag+1,i);
				reverse(mid.begin(), mid.end());
				cout<<mid;
			}
			else{
				reverse(s.begin(), s.end());
				cout<<s;
			}
		}
	}
	return 0;
}

