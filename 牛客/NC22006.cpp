#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a;
	if(a%10<5)
		b = a-a%10;
	else
		b = a-a%10+10;
	cout<<b;
	return 0;
}
