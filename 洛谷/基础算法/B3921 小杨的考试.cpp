#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,ans;
	cin>>a>>b;
	if(a+b<=7){
		cout<<a+b;
		return 0;
	}
	if((a+b)%7==0){
		cout<<"7";
		return 0;
	} 
	ans=(a+b)%7;
	cout<<ans;
	return 0; 
}
