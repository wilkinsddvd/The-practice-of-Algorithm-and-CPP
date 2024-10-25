#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll a,b,c,d,sum;
	cin>>a>>b>>c>>d;
	sum=(abs)(b*d);
	if(b*d>=2147483547){
		cout<<"long long int";
	}else{
		cout<<"int";
	}
	return 0;
} 
