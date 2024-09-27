#include<bits/stdc++.h>
using namespace std;

const int N = 100100;

struct mystack{
	int a[N];
	int t = 0;
	void push(int x){
		a[++t] = x;
	}
	int top(){
		return a[t];
	}
	void pop(){
		t--;
	}
	int empty(){
		return t==0?1:0;
	}
}st;

int h[N],ans[N];

int main(){
	int n;	cin>>n;
	for(int i=1;i<=n;i++)	cin>>h[i];
	for(int i=n;i>=1;i--){
		while(!st.empty() && h[st.top()] <= h[i])
			st.pop();
		if(st.empty())	ans[i] = 0;
		else	ans[i] = st.top();
		st.push(i); 
	}
	for(int i=1;i<=n;i++)	cout<<ans[i]<<endl;
	return 0;
} 
