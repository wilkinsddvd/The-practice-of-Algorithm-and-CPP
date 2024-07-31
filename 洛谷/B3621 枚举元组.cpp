#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n,k;
int a[N];
bool f[N];

void dfs(int step){
	if(step > n){
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}cout<<endl;
		return;
	}
	for(int i=1;i<=k;i++){
		if(f[i] == 0){
			a[step] = i;
			dfs(step+1);		}
	}
}

int main(){
	cin>>n>>k;
	dfs(1);
	return 0;
} 
