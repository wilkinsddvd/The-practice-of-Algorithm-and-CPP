#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b>>c;
		double ans1 = pow(a,2) + pow(b,2) + pow(c,2);
		double ans2 = 3 * a * b * c;
		if(ans1 == ans2)
			cout<<"Yes"<<endl;
		else
			cout<<"No";
	}
	return 0;
}

