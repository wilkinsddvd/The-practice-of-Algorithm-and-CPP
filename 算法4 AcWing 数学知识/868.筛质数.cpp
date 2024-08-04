#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
bool st[N];
int primes[N];
int cnt=0;

void get_primes(int n){
	for(int i=2;i<=n;i++){
		if(!st[i]) primes[cnt++]=i;
		for(int j=i+i;j<=n;j+=i) st[j] = true;
	}
}

int main(){
	int n;
	cin>>n;
	get_primes(n);
	cout<<cnt<<endl;
	
	return 0;	
} 
