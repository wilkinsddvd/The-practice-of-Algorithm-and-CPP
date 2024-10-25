#include<bits/stdc++.h>
using namespace std;

bool check(int x,int a1,int a2,int b1,int b2){
	if(x==1){
		if(a1==b1 || a2==b2){
			return 1;
		}else{
			return 0;
		}
	}
	if(x==2){
		return 0;
	}
	if(x==3){
		if((a1+2==b1 && a2+1==b2) || (a1+2==b1 && a2-1==b2) || (a1+1==b1 && a2+2==b2) || (a1+1==b1 && a2-2==b2) || (a1-1==b1 && a2+2==b2) || (a1-1==b1 && a2-2==b2) || (a1-2==b1 && a2+1==b2) || a1-2==b1 && a2-1==b2){
			return 1;
		}else{
			return 0;
		}
	}
	if(x==4){
		if((a1+2==b1 && a2+2==b2) || (a1+2==b1 && a2-2==b2) || (a1-2==b1 && a2+2==b2) || (a1-2==b1 && a2-2==b2)){
			return 1;
		}else{
			return 0;
		}
	}
} 


int main(){
	int p,x0,y0,x1,y1;
	cin>>p>>x0>>y0>>x1>>y1;
	if(check(p,x0,y0,x1,y1)){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
} 
