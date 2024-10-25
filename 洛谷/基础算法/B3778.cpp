#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b,c;
	cin>>n>>a>>b>>c;
	if(n>5){
		cout<<"art";
	}
	if(n>3 && n<=5){
		if(b<c){
			cout<<"comprehensive";
		}else{
			cout<<"art";
		}
	} 
	if(n<=3){
		if(a<b && a<c){
			cout<<"library";
		}
		if(b<a && b<c){
			cout<<"comprehensive";
		}
		if(c<a && c<b){
			cout<<"art"; 
		}
	}
	return 0;
}
