#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	if(a+b==c){
		cout<<"plus";
		return 0;
	}
	if(a-b==c){
		cout<<"minus";
		return 0;
	}
	cout<<"illegal";
	return 0;
} 
