#include<bits/stdc++.h>
using namespace std;


int re(int x){
	int a,b,c,d,e,f,g,h,sum=0;
	a = x%10;
	b = x/10%10;
	c = x/100%10;
	d = x/1000%10;
	e = x/10000%10;
	f = x/100000%10;
	g = x/1000000%10;
	h = x/10000000%10;
	sum = a+b+c+d+e+f+g;
	return sum;
}

int main(){
	int x;
	cin>>x;
	int a,b,c,d,e,f,g;
	a = re(x);
	cout<<a;
}
// 199584 299376 399168 498960 598752 698544 798336 898128

