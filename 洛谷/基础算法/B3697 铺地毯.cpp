#include<bits/stdc++.h>
using namespace std;

long long a,b,c;
int main(){
	cin>>a>>b>>c;
	if(a%c==0&&b%c==0){
		cout<<(a/c)*(b/c)<<endl;
	}else{
		cout<<"-1";
	}
	return 0;
}
