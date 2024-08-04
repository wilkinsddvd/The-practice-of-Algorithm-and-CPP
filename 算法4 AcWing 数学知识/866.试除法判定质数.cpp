#include<iostream>
using namespace std;

int n;

bool is_prime(int x){
	if(x == 1) return false;
	for(int i=2;i<=x/i;i++){
		if(x%i == 0) return false;
	}
	return true;
}

int main(){
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		cout<<(is_prime(a)?"Yes\n":"No\n");
	}
	return 0;
}
