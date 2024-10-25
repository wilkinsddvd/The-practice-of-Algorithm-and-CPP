#include<bits/stdc++.h>
using namespace std;
string ans;

int main(){
	string s[510],a=" ",c,S[510];
	bool k[510]={0};
	int i=1,b=0,I=1;
	while(a!="0"){
		cin>>s[i];
		a=s[i];
		b++;
		i++;
	}
	for(int d=1;d<b;d++){
		if(!k[d]){
			c=s[d];
			S[++I]=c;
			for(int j=d+1;j<b;j++){
				if(s[j]==c){
					k[j]=1;
				}
			}
		}
	}
	for(int d=1;d<=I;d++){
		ans+=S[d];
	}
	cout<<ans;
	return 0;
} 
