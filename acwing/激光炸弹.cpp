#include<iostream>
using namespace std;

const int N = 5002;
int s[N][N];
int n,r,x,y,w;

int main(){
	int maxw = 0;
	scanf("%d%d",&n,&r);
	r = min(5001,r);
	while(n--){
		scanf("%d%d%d",&x,&y,&w);
		s[x+1][y+1] += w;
	}
	for(int i=1;i<=5001;i++)
		for(int j=1;j<=5001;j++)
		s[i][j] += s[i-1][j] + s[i][j-1]-s[i-1][j-1];
	for(int i = r;i<N;i++)
	{
		for(int j = r;j<N;j++)
		{
			maxw = max(s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r],maxw);
		}
	}
	cout<<maxw;
	return 0;
}
