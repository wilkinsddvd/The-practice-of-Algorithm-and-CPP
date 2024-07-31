#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cha(ll a,ll b,ll c){
	int cha;
	cha=(abs)(a-(b+c));
	return cha;	
}


int main(){
	ll a,b,c,min1;
	cin>>a>>b>>c;
	if(a+b==c){
		cout<<c<<" "<<c;
		return 0;
	}
	if(a+c==b){
		cout<<b<<" "<<b;
		return 0;
	}
	if(b+c==a){
		cout<<a<<" "<<a;
		return 0;
	} 
	ll cha1=cha(a,b,c);
	ll cha2=cha(b,c,a);
	ll cha3=cha(c,a,b);
	
	min1=min(a,min(b,c));
	if(min1==cha1){
		cout<<a<<" "<<b+c;
		return 0;
	}
	if(min1==cha2){
		cout<<b<<" "<<a+c;
		return 0;
	}
	if(min1==cha3){
		cout<<c<<" "<<a+b;
		return 0;
	}
	return 0;
}
