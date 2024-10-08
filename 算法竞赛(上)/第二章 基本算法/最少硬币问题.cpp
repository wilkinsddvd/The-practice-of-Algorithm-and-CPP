#include<bits/stdc++.h>
using namespace std;

const int n = 3;
int coin[] = {1,5,11};

int main(){
	int i,money,sum=0;
	int ans[n] = {0};
	cin>>money;
	for(int i=n-1;i>=0;i--){
		ans[i] = money / coin[i];
		money = money - ans[i] * coin[i];
	}
	for(i = n-1;i>=0;i--)
		sum += ans[i];
		cout<<sum<<endl;
	return 0;
} 
