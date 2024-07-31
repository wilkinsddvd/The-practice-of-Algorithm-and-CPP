#include<bits/stdc++.h>
using namespace std;

int main(){
	char a,c;
	long long b,d,ans=-1;
	cin>>a>>b>>c>>d;
	if((a>='a' && a<='z')&&(c>='a' && c<='z')){
		if(a==c){
			cout<<"valid"<<endl;
			ans=abs(b-d)+1;
			cout<<ans;
			return 0;
		}else{
			cout<<"Invalid"<<endl;
			cout<<ans;
			return 0; 
		}
	}else{
		cout<<"Invalid"<<endl;
	}
	cout<<ans;
	return 0;
}
