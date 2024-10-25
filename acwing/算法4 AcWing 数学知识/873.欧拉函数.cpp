#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		int res = x;
		for(int i=2;i<=x/i;i++){
			// 分解质因数
			if(x % i == 0){
				res = res/i*(i-1);
				while(x%i == 0)
					x /= i;
			} 
		}
		// 最后的质因数
		if(x>1)
			res = res/x*(x-1);
			
		cout<<res<<endl; 
	}
	return 0;
}
