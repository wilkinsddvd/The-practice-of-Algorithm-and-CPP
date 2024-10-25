#include<bits/stdc++.h>
using namespace std;

int Hash[1003]={0};
queue<int>mem;

int main(){
	int m,n;
	cin>>m>>n;
	int cnt=0;
	while(n--){
		int en;
		cin>>en;
		if(!Hash[en]){
			++cnt;
			mem.push(en);
			Hash[en]=1;
			while(mem.size()>m){
				Hash[mem.front()] = 0;
				mem.pop();
			}
		}
	}
	cout<<cnt;
	return 0;
} 
