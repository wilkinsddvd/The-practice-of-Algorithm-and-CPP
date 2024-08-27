#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	int max,min;
	if(x>y){
		max = x;
		min = y;
	}else{
		max = y;
		min = x;
	}
	cout<<max<<'\n'<<min;
	return 0;
}
