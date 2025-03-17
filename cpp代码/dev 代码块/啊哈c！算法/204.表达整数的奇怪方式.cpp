#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y){
	if(!b){
		x = 1,y = 0;
		return a;
	}
	ll d = exgcd(b,a%b,y,x);
	y -= a/b * x;
	return d; 
} 

int main(){
	int n;
	cin>>n;
	
	ll a1,m1;
	cin>>a1>>m1;

	for(int i=0;i<n-1;i++){
		ll a2,m2,k1,k2;
		cin>>a2>>m2;
		ll d = exgcd(a1, a2, k1, k2);
		// d | m2-m1 表示有解，否则输出-1
		if((m2-m1) % d){
			puts("-1");
			return 0;
		} 
		
		// 此时 k1 是 k1 * a1 + k2 * a2 = d 的解，所以要乘上(m2-m1)/d
		k1 *= (m2-m1) / d;
		ll t = a2/d;
		// 模 t 是因为 K1 = k1 + kt, k1 是不断迭代的结果,取模保证k1取比较小的模
		k1 = (k1 % t + t) % t;
		// 更新 m1 ，m1 不断迭代，可以看作方程的解
		m1 = a1 * k1 + m1;
		// 更新a1, a1, a2 , ...  , an的最小公倍数
		a1 = a1 * a2 / d; 
	}
	cout<<((m1 % a1 + a1) % a1) <<endl;
	return 0;
}
