#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1000010;
int primes[N],phi[N],cnt;
bool st[N];

ll get_eulers(int n){
	ll res = 0;
	phi[1] = 1;
	
	for(int i=2;i<=n;i++){
		if(!st[i])
			primes[cnt++] = i, phi[i] = i-1;
		for(int j=0;primes[j] <= n/i;j++){
			st[primes[j] * i] = true;
			if(i % primes[j] == 0){
				phi[primes[j]*i] = phi[i] * primes[j];
				break;
			}
			phi[primes[j] * i] = phi[i]*(primes[j] - 1);
		}
	}
	for(int i=1;i<=n;i++)
		res += phi[i];
	
	return res;
}

int main(){
	int n;
	cin>>n;
	cout<<get_eulers(n)<<endl;
	return 0;
} 
