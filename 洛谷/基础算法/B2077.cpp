#include<bits/stdc++.h>
using namespace std;

long long n;

int main(){
	cin>>n;
	while(n!=1){
		if(n%2 != 0){
			cout<<n<<"*3+1="<<n*3+1<<endl;
			n=n*3+1;
		}
		else{
			cout<<n<<"/2="<<n/2<<endl;
			n=n/2;
		}
	}
	cout<<"End"<<endl;
	return 0;
}
