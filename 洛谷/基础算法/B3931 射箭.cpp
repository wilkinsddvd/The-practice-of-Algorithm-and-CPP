#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,cnt=0;
	cin>>a>>b>>c; 
	if(a>(b+c)){
		cnt++; 
	}
	if(b>(a+c)){
		cnt++;
	}
	if(c>(a+b)){
		cnt++;
	}
	cout<<cnt;
	return 0;
}
