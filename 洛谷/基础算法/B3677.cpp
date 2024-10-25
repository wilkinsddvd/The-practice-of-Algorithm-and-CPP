#include<bits/stdc++.h>
using namespace std;

long long a,b;

int main(){
	cin>>a>>b;
	if(a<0 && b%2 != 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	if(a%2 != 0 || b == 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
