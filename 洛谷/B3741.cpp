#include<bits/stdc++.h>
using namespace std;

int check(int a1,int a2,int b1,int b2){
	int ans;
	if(a1==b1){
		if(a2<b2){
			ans=1;
			return ans;
		}else{
			ans=0;
			return ans;
		}
	} 
	if(a1>b1){
		ans=1;
		return ans;
	}else{
		ans=0;
		return ans;
	}
}

int output(int x){
	if(x==1){
		cout<<"\""<<"\\"<<"n"<<"\"";
		return 0;
	}
	if(x==0){
		cout<<"\""<<"\\"<<"t"<<"\"";
		return 0;
	}	
	
}

int main(){
	int a,b,c,d,ans;
	cin>>a>>b>>c>>d;
	ans=check(a,b,c,d);
	output(ans);
	return 0;
}
