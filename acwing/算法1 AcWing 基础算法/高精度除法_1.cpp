#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> vi;
vi aa;

vi div(vi &aa,int b,int &r){
	vi c;
	int t=0;
	// 只有除法逆序操作 
	for(int i=aa.size()-1;i>=0;i--){
		r = r*10  + aa[i];
		c.push_back(r/b);
		r %= b;
	}
	
	// 上面是逆序，这里再逆序一下，最后主函数里逆序输出九位正序结果 
	reverse(c.begin(),c.end());
	
	//去除前导0,注意c是最后结果的逆序，注意结果为0的情况 c.size() > 1
	while(c.size()>1 && c.back() == 0)
		c.pop_back();
	return c; 
}

int main(){
	string a;
	int b,r;
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--)
		aa.push_back(a[i]-'0');
	
	vi c = div(aa,b,r);
	for(int i=c.size()-1;i>=0;i--)
		cout<<c[i];
	cout<<endl<<r;
	return 0;
}
