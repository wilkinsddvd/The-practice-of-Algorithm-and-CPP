#include<bits/stdc++.h>
using namespace std;

// 试除法判断质数
bool is_prime(int x){
	if(x<2) return false;
	// 只需枚举一部分 使得 i<= x/i 时间复杂度为 √n
	for(int i=2;i<=x/i;i++)
		if(x%i == 0)
			return false;
	return true; 
} 

// 试除法分解质因数
void divide(int n){
	for(int i=2;i<=n/i;i++){
		if(n%i == 0){
			int cnt = 0;
			while(n%i == 0){
				n /= i;
				cnt++; 
			}
			cout<<i<<cnt<<endl;
		}
	}
	// 本身就是质数
	if(n > 1) cout<<n<<1<<endl;
	cout<<endl; 
} 

int main(){
	
}
