#include<bits/stdc++.h>
using namespace std;
typedef long double db;

int main(){
	db a,b,c,d,e,f,cnt=0;
	cin>>a>>b>>c>>d>>e>>f;
	if(a<60){
		cnt++;
	}
	if(b<60){
		cnt++;
	}
	if(c<60){
		cnt++;
	}
	if(cnt<=1){
		cout<<"PASS"<<endl;
	}else{
		cout<<"FALL"<<endl;
	}
	int ans=(a*d+b*e+c*f)/(d+e+f);
	if(ans<60){
		cout<<"FAIL";
	}else{
		cout<<"PASS";
	}
	return 0;
} 
