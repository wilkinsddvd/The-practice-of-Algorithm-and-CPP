#include<bits/stdc++.h>
using namespace std;


bool check(double x){
	// ���x�Ƿ�����ĳ������	
} 

double bsearch_3(double l,double r){
	const double eps=1e-6;
	while(r-1>eps){
		double mid = l+r>>1;
		if(check(mid))
			r = mid;
		else
			l = mid;
	}
	return l;
} 


