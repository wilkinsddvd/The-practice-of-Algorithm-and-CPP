#include<bits/stdc++.h>
vector<int> get_divisors(int n){
	vector<int> res;
 
	for(int i=1;i<=n/i;i++){//ֻѭ��n/i��
		if(n%i==0){//�ҵ�Լ��
			res.push_back(i);
			if(n/i!=i) res.push_back(n/i);//������i�ɶԵ��Ǹ�Լ��
		}
	}
	sort(res.begin(),res.end());//����
	return res;
}
