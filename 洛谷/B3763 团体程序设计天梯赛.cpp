#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,d,e,f,g,h;
	int i,j,k,l;
	int m,n,o,sum1,sum2,sum3,ans;
	cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o;
	sum1=a+b+c+d+e+f+g+h;
	if(sum1>80){
		sum2=i+j+k+l;
		if(sum2>40){
			sum3=m+n+o;
			ans=sum1+sum2+sum3;
			cout<<ans;
			return 0;
		}
		ans=sum1+sum2;
		cout<<ans;
		return 0;
	}
	ans=sum1;
	cout<<ans;
	return 0;
} 
