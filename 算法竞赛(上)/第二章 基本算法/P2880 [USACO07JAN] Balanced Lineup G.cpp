#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;
const int N = 50005;
int n,m;
int a[N],dp_max[N][22],dp_min[N][21];
int LOG2[N];

void st_init(){
	LOG2[0] = -1;
	for(int i=1;i<=N;i++)	LOG2[i] = LOG2[i>>1] + 1;
	for(int i=1;i<=n;i++){
		dp_min[i][0] = a[i];
		dp_max[i][0] = a[i];
	} 
	int p = (int)(log(double(n)) / log(2.0));
	for(int k=1;k<=p;k++)
		for(int s=1;s+(1 << k) <= n+1;s++){
			dp_max[s][k] = max(dp_max[s][k-1],dp_max[s+(1 << (k-1))][k-1]);
			dp_min[s][k] = min(dp_min[s][k-1],dp_min[s+(1 << (k-1))][k-1]); 
		}
}

int st_query(int L,int R){
	int k = (int)(log(double(R-L+1)) / log(2.0));
	int x = max(dp_max[L][k],dp_max[R- (1 << k) + 1][k]);
	int y = min(dp_min[L][k],dp_min[R- (1 << k) + 1][k]);
	return x-y;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	st_init();
	for(int i=1;i<=m;i++){
		int L,R;	cin>>L>>R;
		cout<<st_query(L,R)<<endl; 
	}
	return 0;
}
