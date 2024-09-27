#include<bits/stdc++.h>
using namespace std;

const int N = 100100;
struct mystack{
	char a[N];
	int t = 0;
	void push(char x){
		a[++t] = x;
	} 
	char top(){
		return a[t];
	}
	void pop(){
		t--;
	}
	int empty(){
		return t==0?1:0;
	}
}st;

int main(){ 
	int n;	cin>>n;	getchar();
	while(n--){
		while(1){
			char ch = getchar();
			if(ch == ' ' || ch == '\n' || ch == EOF){
				while(!st.empty()){
					cout<<st.top();
					st.pop();
				}
				if(ch == '\n' || ch == EOF)	break;
				cout<<" ";
			}
			else	st.push(ch);
		}
		cout<<"\n";
	}
	return 0;
} 
