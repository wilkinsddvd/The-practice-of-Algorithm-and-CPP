#include<bits/stdc++.h>
vector<int> get_divisors(int n){
	vector<int> res;
 
	for(int i=1;i<=n/i;i++){//只循环n/i次
		if(n%i==0){//找到约数
			res.push_back(i);
			if(n/i!=i) res.push_back(n/i);//存入与i成对的那个约数
		}
	}
	sort(res.begin(),res.end());//排序
	return res;
}
