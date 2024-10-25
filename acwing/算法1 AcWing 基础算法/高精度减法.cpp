#include<iostream>
#include<vector>
using namespace std;

typedef vector<int> vi;

bool cmp (vi &a,vi &b){
	if(a.size() != b.size())
		return a.size() > b.size();
	for(int i=a.size()-1;i>=0;i--){
		if(a[i] != b[i])
			return a[i] > b[i];
	}
	return 1;
} 

vi sub(vi &a,vi &b){
	vi c;
	int t =0;
	for(int i=0;i<a.size();i++){
		t = a[i] - t;
		if(i<b.size())
			t -= b[i];
		c.push_back((t+10)%10);
		t = t<0?1:0;
	}
	while(c.size() > 1 && c.back()==0)
		c.pop_back();
	return c; 
}

int main(){
	string a,b;
	vi A,B;
	cin>>a>>b;
	for(int i=a.size()-1;i>=0;i--)
		A.push_back(a[i]-'0');
	for(int i=b.size()-1;i>=0;i--)
		B.push_back(b[i]-'0');
	
	if(cmp(A,B)){
		auto c = sub(A,B);
		for(int i=c.size()-1;i>=0;i--)
			cout<<c[i]; 
	}else{
		auto c = sub(B,A);
		cout<<"-";
		for(int i=c.size()-1;i>=0;i--)
			cout<<c[i];
	}
	return 0;
}
