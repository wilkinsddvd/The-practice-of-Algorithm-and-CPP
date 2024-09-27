#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;	cin>>n;	getchar();
	while(n--){
		stack<char>s;
		while(1){
			char ch = getchar();
			if(ch == ' ' || ch == '\n' || ch == EOF){
				while(!s.empty()){
					cout<<s.top();
					s.pop();
				}
				if(ch == '\n' || ch == EOF)	break;
				cout<<" ";
			}
			else	s.push(ch);
		}
		cout<<"\n";
	}
	return 0;
} 
