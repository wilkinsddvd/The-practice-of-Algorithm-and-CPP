#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
int n;

int qmi(int a, int b, int p){
	int res = 1%p;
	while(b){
		if(b & 1) 
			res = (LL)res * a % p;
			b >>= 1;
			a = (LL)a * a % p;
	}
	return res;
} 

int main(){
	cin>>n;
	int a,p;
	while(n--){
		cin>>a>>p;
		// 如果 a%p 不等于 0 ， 
		// 若a<p , 由p为质数，a,p互质
		// 若a>p , p不等整除a，a,p互质
		if(a % p) 
			cout<<qmi(a,p-2,p)<<endl;
		else
			puts("impossible"); 
	} 
	return 0;
}
