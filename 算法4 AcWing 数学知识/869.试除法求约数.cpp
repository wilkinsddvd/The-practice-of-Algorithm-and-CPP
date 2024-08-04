#include<bits/stdc++.h>
using namespace std;

int n;

void get_divisors(int a){
	vector<int>res;
	for(int i=1;i<=a/i;i++){
		if(a%i == 0){
			res.push_back(i);
			// 防止平方根多次出现
			if(i!=a/i) 
				res.push_back(a/i); 
		}
	}
	// 从大到小排序
	sort(res.begin(),res.end());
	
	for(int t:res)
		cout<<t<<" ";
	cout<<endl; 
} 

int main(){
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		get_divisors(a); 
	}
	return 0;
}
