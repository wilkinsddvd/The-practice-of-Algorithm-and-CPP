#include<bits/stdc++.h>
using namespace std;

int n,k,t;

struct node{
	int x,y;
	int flag;
}a[1005];

int getdist(int x,int y,int z,int w){
	return (x-z)*(x-z)+(y-w)*(y-w);
}

int main(){
	cin>>n>>k>>t;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=k;++i){
		int x,y;
		cin>>x>>y;
		for(int j=1;j<=n;++j){
			if(a[j].x==x && a[j].y==y){
				a[j].flag = 1;
			}
		}
	}
	int res=0;
	for(int i=1;i<=t;++i){
		int x,y;
		cin>>x>>y;
		int currentmaxdistance = -1;
		int ans;
		for(int j=1;j<=n;++j){
			if(getdist(x,y,a[j].x,a[j].y) > currentmaxdistance){
				ans = j;
				currentmaxdistance = getdist(x,y,a[j].x,a[j].y);	
			}
		}
		if(a[ans].flag){
			++res;
		}
	}
	cout<<res<<endl;
	return 0;
}
