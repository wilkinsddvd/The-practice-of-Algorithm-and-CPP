#include<bits/stdc++.h>
using namespace std;

struct node{
	node(){}
	node(string ss,int tt){
		s = ss;
		t = tt;
	}
	string s;
	int t;
};
// 1 map 
map<string,bool>mp;
// 2 set
// set<string>visited;

queue<node>q;

void solve(){
	while(!q.empty()){
		node now = q.front();
		q.pop();
		string s = now.s;
		int step = now.t;
		if(s == "087654321"){
			cout<<step<<endl;
			break;
		}
		int i;
		for(i=0;i<10;i++)
			if(s[i] == '0')	break;
		for(int j=i-2;j<=i+2;j++){
			int k = (j+9) % 9;
			if(k == i)	continue;
			string news = s;
			char tmp = news[i];
			news[i] = news[k];
			news[k] = tmp;
		
// 1 map
			if(!mp[news]){
				mp[news] = true;
				q.push(node(news,step+1));
			} 
		}
// 2 set
//		if(visited.count(news) == 0){
//			visited.insert(news);
//			q.push(node(news,step+1));
//		} 
	}
} 

int main(){
	string s = "012345678";
	q.push(node(s,0));
// 1 map
	mp[s] = 1;
	solve();
	return 0; 
} 
