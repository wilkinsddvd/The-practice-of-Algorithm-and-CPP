#include<bits/stdc++.h>
using namespace std;

int n,m;

struct node{
	string name;
	long long val;
}s[100005],h[100005];

int cnts,cnth;

int cmp(node x,node y){
	return x.val>y.val;
}
 
int main(){
	cin>>n>>m;
	for(int i=1;i<=n+m;++i){
		string name,v;
		long long val;
		cin>>name>>v>>val;
		if(v=="H"){
			++cnth;
			h[cnth].name=name;
			h[cnth].val=val;
		}else{
			++cnts;
			s[cnts].name=name;
			s[cnts].val=val;
		}
	}	
	sort(s+1,s+cnts+1,cmp);
	sort(h+1,h+cnth+1,cmp);
	cout<<h[3].name<<endl;
	for(int i=6;i<=9;++i){
		cout<<s[i].name<<endl;
	}
	return 0;
}
