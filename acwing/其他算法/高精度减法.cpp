#include<iostream>
#include<vector>
using namespace std;

typedef vector<int>vi;

bool cmp(vi &a,vi &b){
	if(a.size()!= b.size()) return a.size()>b.size();
	for(int i=a.size()-1;i>=0;i--)
	{
		if(a[i]!=b[i]) return a[i]>b[i];
	}
	return true;
}

vi sub(vi &a,vi &b){
	vi c;
	int t = 0;
	for(int i = 0;i<a.size();i++)
	{
		t = a[i]-t;
		if(i<b.size()) t-=b[i];
		c.push_back((t+10)%10);
		t = t<0 ? 1 : 0;
	}
	while(c.size()>1 && c.back()=0)
}
