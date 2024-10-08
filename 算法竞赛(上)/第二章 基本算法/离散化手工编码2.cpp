#include<bits/stdc++.h>
using namespace std;

const int N = 500010;
struct data{
	int val;
	int id;
}olda[N];

int newa[N];
bool cmp(data x,data y){
	return x.val < y.val;
}

int main(){
	int n;	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>olda[i].val;
		olda[i].id = i;
	}
	sort(olda+1,olda+1+n,cmp);
	for(int i=1;i<=n;i++){
		newa[olda[i].id] = i;
//		if(olda[i].val == olda[i-1].val)
//			newa[olda[i].id] = newa[olda[i-1].id];
	}
	for(int i=1;i<=n;i++)	cout<<newa[i]<<" ";
	return 0;
}
