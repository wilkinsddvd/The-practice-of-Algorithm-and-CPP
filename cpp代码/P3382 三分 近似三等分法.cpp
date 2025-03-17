#include<bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

int n;
double a[15];

double f(double x){
	double s = 0;
	for(int i=n;i>=0;i--)	s = s*x + a[i];
	return s;
} 

int main(){
	double L,R;
	cin>>n>>L>>R;
	for(int i=n;i>=0;i--)	cin>>a[i];
	while(R-L > eps){
		double mid = L + (R-L)/2;
		if(f(mid-eps) > f(mid))	R = mid;
		else	L = mid;
	} 
	cout<<fixed<<setprecision(5)<<L;
	return 0; 
}
