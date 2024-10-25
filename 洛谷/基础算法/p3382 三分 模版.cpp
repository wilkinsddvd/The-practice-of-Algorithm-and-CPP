#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;
int n;
double a[15];
double f(double x){
	double s=0;
	for(int i=n;i>=0;i--)
		s=s*x+a[i];
	return s; 
} 

int main(){
	double L,R;
	cin>>n>>L>>R;
	for(int i=n;i>=0;i--)
		cin>>a[i];
	while(R-L >eps){
		double k = (R-L)/3.0;
		double mid1 = L+k, mid2 = R-k;
		if(f(mid1) > f(mid2)) 
			R = mid2;
		else
			L = mid1; 
	}
	cout<<fixed<<setprecision(5)<<L;
	return 0;
}
