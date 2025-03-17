#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, ans;
    string s;
    cin>>N>>s;
    for(int i=1;i<=5;i++){
    	cout<<s;
	}
	cout<<endl;
	cout<<setw(2);
	for(int i=1;i<=3;i++){
		cout<<s;
	}
	cout<<endl;
	cout<<setw(3);
	for(int i=1;i<=1;i++){
		cout<<s; 
	}
	cout<<endl;
	cout<<setw(2);
	for(int i=1;i<=3;i++)
    	cout<<s;
    cout<<endl;
    for(int i=1;i<=5;i++)
    	cout<<s;
    cout<<endl;
    ans = N - 17;
    cout<<ans;
    return 0;
}
