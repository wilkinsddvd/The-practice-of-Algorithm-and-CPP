// not complete 
#include<bits/stdc++.h>
using namespace std;

struct matrix{
	int m[N][N];
}; 

matrix operator * (const matrix&a, const matrix&b){
	matrix c;
	memset(c,m,0,sizeof(c.m));
	for(int i=1;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				c.m[i][j] = (c.m[i][j] + a.m[i][j] * b.m[k][j]) % mod;
			}
		}
	}
	return c;
}

