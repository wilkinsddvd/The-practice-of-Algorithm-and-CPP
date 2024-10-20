#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int num[N];
int n,depth;
bool dfs(int now,int d){
	if(d > depth)	return 0;
	if(now == n)	return 1;
	if(now << (depth - d) < n)
		return 0;
	num[d] = now;
	for(int i=0;i<=d;i++){
		if(dfs(now + num[i],d+1))	return 1;
		else if(dfs(now - num[i],d+1))	return 1;
	}
	return 0;
} 

int main(){
 	while(~scanf("%d",&n)&&n){
 		for(depth = 0;;depth++){
 			memset(num,0,sizeof(num));
 			if(dfs(1,0))	 break;
		}	
		cout<<depth<<endl;
	}
	return 0;
 }
