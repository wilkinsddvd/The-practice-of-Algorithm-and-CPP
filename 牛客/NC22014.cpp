#include<bits/stdc++.h>
using namespace std;

int main(){
	int x;
	cin>>x;
	if(x%2==0 && x>2){
		cout<<"YES, you can divide the watermelon into two even parts.";
	}else{
		cout<<"NO, you can't divide the watermelon into two even parts.";
	}
	return 0;
}
