#include<bits/stdc++.h>
using namespace std;

int n;
string s[1007];

int main(){
	while(cin>>s[++n]);
		--n;
	for(int i=n;i>=1;i--){
		for(int j=0;j<(int)s[i].size();j++){
			if(s[i][j] >= 'a' && s[i][j] <= 'z')
				s[i][j] -= 'a' - 'A';
			else if(s[i][j] >= 'A' && s[i][j] <= 'Z')
				s[i][j] -= 'A' - 'a';
		}
		if(s[i][0] >= '0' && s[i][0] <= '9')
			for(int j=(int)s[i].size()-1;j>=0;j--)
				cout<<s[i][j];
		else
			cout<<s[i];
		if(i!=1)
			cout<<" ";
	}
}
// 在本地上停不下，不清楚原因，但是OJ上过了 
