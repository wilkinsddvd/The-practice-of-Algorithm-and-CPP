#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;	cin>>n;
	while(n--){
		string s;	cin>>s;
		bool ans = 1;
		int i = 0,j = s.size() - 1;
		while(i<j){
			if(s[i] != s[j]){
				ans = 0;
				break;
			}
			i++;	j--;
		}
		if(ans)	cout<<"yes"<<endl;
		else	cout<<"no"<<endl; 
	}
	return 0;
}
