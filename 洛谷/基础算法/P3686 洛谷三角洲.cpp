#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	a = min(a,b+c);
	b = min(b,a+c);
	c = min(c,a+b);
	cout<<a<<'\n'<<b<<'\n'<<c;
	return 0; 
}
