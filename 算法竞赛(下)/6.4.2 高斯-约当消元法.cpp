#include<bits/stdc++.h>
using namespace std;

double a[105][105];
double eps = 1e-7;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;++j)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++){
		int max=i;
		for(int j=i+1;j<=n;++j)s
			if(fabs(a[j][i])>fabs(a[max][i]))
				max=j;
		for(int j=1;j<=n+1;++j)
			swap(a[i][j],a[max][j]);
		if(fabs(a[i][i])<eps){
			puts("No Solution");
			return 0;
		}
		for(int j=n+1;j>=1;j--){
			a[i][j] = a[i][j]/a[i][i];
		}
		for(int j=1;j<=n;++j){
			if(j!=i){
				double temp=a[j][i]/a[i][i];
				for(int k=1;k<=n+1;++k)
					a[j][k] -= a[i][k]*temp;
			}
		}
	}
	for(int i=1;i<=n;++i)
		cout<<fixed<<setprecision(2)<<a[i][n+1]<<endl;
	return 0;
} 
