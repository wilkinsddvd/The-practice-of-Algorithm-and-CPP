#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,c,d,sum1,sum2;
	cin>>a>>b>>c>>d;
	sum1=(c+1)*b+d;
	sum2=a*b; 
	
	if(sum2<sum1){
		cout<<"Segmentation fault."<<'\n';
	}else{
		cout<<"Program ends with return value 0."<<'\n';
	}
	return 0;
}
