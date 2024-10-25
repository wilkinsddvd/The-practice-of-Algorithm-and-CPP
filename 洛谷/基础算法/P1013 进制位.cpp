#include<bits/stdc++.h>
using namespace std;

int n;
map<char,int>m;
int p[15];
string s[15][15];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>s[i][j];
	for(int i=2;i<=n;i++){
		int sum = 0;
		for(int j=2;j<=n;j++){
			if(s[i][j].size() == 2)
				sum++;
		} 
		p[i] = sum;
		m.insert({s[i][1][0],sum});
	}
	for(int i=2;i<=n;++i)
		for(int j=2;j<=n;j++){
			int a = p[i];
			int b = p[j];
			int c;
			if(s[i][j].size() == 2)
				c = m[s[i][j][0]]*(n-1)+m[s[i][j][1]];
			else
				c = m[s[i][j][0]];
			
			if(c!=a+b){
				cout<<"ERROR!"<<endl;
				return 0;
			}
		} 
	for(int i=2;i<=n;++i)
		cout<<s[i][1]<<"="<<p[i]<<" ";
	cout<<endl<<n-1;
	return 0;
}
