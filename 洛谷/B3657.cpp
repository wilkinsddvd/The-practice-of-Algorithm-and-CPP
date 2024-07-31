#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	cin>>x>>y;
	if(x>y){
		cout<<90 * y + 60 *(x-y)<<endl;
	}else if(x<y){
		cout<<90 * x + 40 *(y-x)<<endl;
	}else{
		cout<<90 * x<<endl;
	}
	return 0;
}
