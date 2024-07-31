#include<bits/stdc++.h>
using namespace std;

bool re(int x,int y,int z){
	int sum,ans1,ans2;
	sum = x+y+z;
	if(sum > 100)
		return 0;
	if(y % 5 != 0)
		return 0;
	if(z % 7 != 0)
		return 0;
	ans1 = x-y;
	ans2 = y-z;
	if(ans1 < ans2)
		return 0; 
	return 1;
}

int main(){
	int a,b,c,ans;
	cin>>a>>b>>c;
	ans = re(a,b,c);
	if(ans){
		cout<<"Yes";
		return 0;
	}
	cout<<"No";
	return 0;
} 
