#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,s,max=0,i,day=0;
	for(i = 1;i < 8;i++){
		cin>>a>>b;
		s=a+b;
		if((s>max)&&(s>8)) max=s,day=i;
	}
	cout<<day;
	return 0;
}
