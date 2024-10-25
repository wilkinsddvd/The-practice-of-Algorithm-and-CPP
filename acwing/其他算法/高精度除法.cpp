#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vi;

vi aa;

vi div(vi &aa,int b,int &r){
	vi c;
	int t = 0;
	for(int i=aa.size()-1;i>=0;i--){
		r = r*10+aa[i];
		c.push_back(r/b);
		r %= b;
	}
	reverse(c.begin(),c.end());
	while(c.size() > 1 && c.back() == 0) c.pop_back();
	return c;
}

int main(){
	string a;
	int b,r;
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--) aa.push_back(a[i]-'0');
	
	vi c = div(aa,b,r);
	for(int i=c.size()-1;i>=0;i--) printf("%d",c[i]);
	printf("\n%d",r);
	return 0;
}

// 能跑，但是数据不太对…… 
