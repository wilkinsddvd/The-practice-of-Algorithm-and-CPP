#include<bits/stdc++.h>
using namespace std;

int n;

void get_divisors(int a){
	vector<int>res;
	for(int i=1;i<=a/i;i++){
		if(a%i == 0){
			res.push_back(i);
			// ��ֹƽ������γ���
			if(i!=a/i) 
				res.push_back(a/i); 
		}
	}
	// �Ӵ�С����
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
