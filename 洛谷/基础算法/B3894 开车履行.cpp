#include<bits/stdc++.h>
using namespace std;

int main(){
	double a,b,c,d,e,f,g,ans1,ans2=0;
	cin>>a>>b>>c>>d;
	e = b+d;
	ans1 = a*b+c*d;
	ans2 = ans1/e;
	cout<<fixed<<setprecision(1)<<ans1<<"\n";
	cout<<ans2;
	return 0;
} 
