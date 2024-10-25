#include<bits/stdc++.h>
using namespace std;

int re(int x){
	int a,b,c,sum;
	a = x/100;
	b = x/10%10;
	c = x%10;
	sum = a+b+c;
	return sum;
}

int re1(int x){
	int a,b,c,sum;
	a = x/100;
	b = x/10%10;
	c = x%10; 
	sum = pow(a+b+c,2);
	return sum;
}

int re2(int x){
	int a,b,c,sum;
	a = x/100;
	b = x/10%10;
	c = x%10;
	sum = pow(a+b+c,3);
	return sum;
}


int main(){
	int a,ans1,ans2,ans3;
	cin>>a;
	ans1 = re(a);
	ans2 = re1(a);
	ans3 = re2(a);
	cout<<ans1<<endl;
	cout<<ans2<<endl;
	cout<<ans3;
	return 0;
} 
