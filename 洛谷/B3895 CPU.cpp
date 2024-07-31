#include<bits/stdc++.h>
using namespace std;

bool check(int a,int b){
	if(a==0 || b==0){
		return 0;
	}
	if(a*2<b || a>b ){
		return 0;
	}
	if(a==b){
		return 0;
	}
	return 1;
}

int main(){
	int a,b,c;
	cin>>a>>b;
	if(check(a,b)==0){
		cout<<"Error";
		return 0;
	}
	int ans1=b/2,ans2=a-(b/2);
	while(ans1*2+ans2!=b){
		ans1--;
		ans2++;
	}
	cout<<ans1<<" "<<ans2;
	return 0; 
}
