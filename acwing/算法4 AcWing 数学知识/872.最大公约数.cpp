#include<iostream>
using namespace std;

int gcd(int m,int n){
	return m%n == 0 ? n : gcd(n,m%n);
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		cout<<gcd(a,b)<<endl;
	}
	return 0;
}
