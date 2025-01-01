#include<bits/stdc++.h>
using namespace std;

int digui(int n){
	if(n==1){
		return 1;
	}
	return n*digui(n-1);
}

int main(){
	int n;
	cin>>n;
	n = digui(n);
	cout<<n;
	return 0;
} 
