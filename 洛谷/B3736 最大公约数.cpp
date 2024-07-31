#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
	int res=0;
	while(x!=y){
		if(x>y){
			x -= y;
		}else{
			y -= x;
		}
	}
	return x;
} 

int main(){
	int a,b,c,ans1,ans2;
	cin>>a>>b>>c;
	ans1 = gcd(a,b);
	ans2 = gcd(ans1,c);
	cout<<ans2;
	return 0;
}
