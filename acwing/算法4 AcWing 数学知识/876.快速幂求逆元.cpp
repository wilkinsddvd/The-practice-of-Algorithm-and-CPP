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
		// ��� a%p ������ 0 �� 
		// ��a<p , ��pΪ������a,p����
		// ��a>p , p��������a��a,p����
		if(a % p) 
			cout<<qmi(a,p-2,p)<<endl;
		else
			puts("impossible"); 
	} 
	return 0;
}
