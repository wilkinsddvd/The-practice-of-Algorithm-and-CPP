#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x,y;
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		cout<<"("<<x<<","<<i<<")"<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<"("<<i<<","<<y<<")"<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i-j==x-y){
				cout<<"("<<i<<","<<j<<")"<<" ";
			}
		}
	}
	cout<<endl;
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n;j++){
			if(i+j==x+y){
				cout<<"("<<i<<","<<j<<")"<<" ";
			}
		}
	}
	cout<<endl;
	return 0;
}
