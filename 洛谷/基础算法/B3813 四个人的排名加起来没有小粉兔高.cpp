#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,d,sum;
	cin>>a>>b>>c>>d;
	sum=a+b+c+d;
	if(sum>=51){
		cout<<"Rabbit lose";
	}else{
		cout<<"Rabbit wins";
	}
	return 0; 
}
