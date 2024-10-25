#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,d,ans,sum,sum2;
	cin>>a>>b>>c>>d;
	sum=2*a+5*b+3*c;
	if(d>=sum){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	sum2=abs(d-sum);
	cout<<sum2;
	return 0;
}
