#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	while(cin>>s){
		for(int i=0;i<=s.size();i++){
			if(i%2==0){
				s[i]-=32;
			}
		}
		cout<<s<<" ";
	}
	return 0;
} 
