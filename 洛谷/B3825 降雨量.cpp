#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,ans1;
	cin>>a>>b;
	ans1=a;
	if(ans1>=50){
		cout<<"Torrential Rain"; 
	}
	if(ans1>=25 && ans1<50 ){
		cout<<"Heavy Rain";
	}
	if(ans1>=10 && ans1<25){
		cout<<"Moderate Rain";
	}
	if(ans1<10){
		cout<<"Drizzle";
	}
	if(b==1){
		if(a>=20){
			cout<<endl<<"YES";
		}else{
			cout<<endl<<"NO";
		}
	}
	return 0;
}
