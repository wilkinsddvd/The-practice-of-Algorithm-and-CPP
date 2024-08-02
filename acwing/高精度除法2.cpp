#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<long long> div(vector<long long> &a,long long b,long long &r)
{
	vector<long long> c;
	r = 0;
	for(int i=a.size()-1;i>=0;i--){
		r = r*10+a[i];
		c.push_back(r/b);
		r %= b;
	}
	reverse(c.begin(),c.end());
	while(c.size()>1 && c.back() == 0) c.pop_back();
	return c;
}

int main(){
	string a;
	long long b;
	cin>>a>>b;
	vector<long long>aa;
	for(int i=a.size()-1;i>=0;i--)
		aa.push_back(a[i]-'0');
	long long r;
	auto c = div(aa,b,r);
	for(int i = c.size()-1;i>=0;i--)
		printf("%lld",c[i]);
	return 0;
}
// 29行报错， auto c所在行 
