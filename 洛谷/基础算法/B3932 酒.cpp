#include<bits/stdc++.h>
using namespace std;
typedef double db;

db check(db a,db b,db c){
	db ans1,ans2;
	if(a>b&&a>c){
		cout<<"1"<<" ";
		cout<<fixed<<setprecision(2)<<a;
		return 0;
	}
	if(b>c&&b>a){
		cout<<"2"<<" ";
		cout<<fixed<<setprecision(2)<<b;
		return 0;
	}
	if(c>a&&c>b){
		cout<<"3"<<" ";
		cout<<fixed<<setprecision(2)<<c;
		return 0;
	}
}

int main(){
	db a,b,c,d,e,x,y,sum1,sum2,sum3;
	cin>>a>>b>>c>>d>>e>>x>>y;
	sum1=a*x+b*y;
	sum2=c*y;
	sum3=d*y+e;
	check(sum1,sum2,sum3);
	return 0;
}
