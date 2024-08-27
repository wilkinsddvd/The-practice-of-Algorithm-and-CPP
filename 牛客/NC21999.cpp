#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c,ans;
	cin>>a>>b>>c;
	ans = 2*(a*b+b*c+a*c);
	cout<<ans<<endl;
	ans = a*b*c;
	cout<<ans;
	return 0;
}
