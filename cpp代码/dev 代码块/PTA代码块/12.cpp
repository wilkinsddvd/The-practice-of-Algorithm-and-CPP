#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll x,y;
	cin>>x;
	for(int i=1;i<=1e15;i++){
		y = x * i;
		for(int j=1;j<=20;j++){
			int k = j;
			int	z = 1 + pow(10,k);
			if(y = z){
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}
