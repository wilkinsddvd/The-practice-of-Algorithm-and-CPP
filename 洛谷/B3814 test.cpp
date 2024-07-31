#include<bits/stdc++.h>
using namespace std;

bool check1(int a1,int a2,int b1,int b2){
	if((a1+1==b1 && a2+2==b2) || (a1+1==b1 && a2-2==b2) || (a1-1==b1 && a2+2==b2) || (a1-1==b1 && a2-2==b2) || (a1+2==b1 && a2+1==b2) || (a1+2==b1 && a2-1==b2) || (a1-2==b1 && a2+1==b2) || (a1-2==b1 && a2-1==b2)){
		return 1;
	}
	return 0;
}


int main(){
	int a1,a2,b1,b2,c1,c2;
	bool ans1=1,ans2=1;
	cin>>a1>>a2>>b1>>b2>>c1>>c2;
	ans1=check1(c1,c2,a1,a2);
	ans2=check1(c1,c2,b1,b2);
	 
	if(ans1 && ans2){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}
