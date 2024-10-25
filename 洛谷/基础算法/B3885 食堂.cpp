#include<bits/stdc++.h>
using namespace std;

int main(){
	long long a,b,R,V,M,ans1,ans2,ans3;
	cin>>a>>b>>R>>V>>M;
	ans1 = 2 * a * 2 * R + b * R;
	ans2 = 2 * a * 3 * V + b * V;
	ans3 = 2 * a * 3 * M + b * M;
	cout<<ans1<<" "<<ans2<<" "<<ans3;
	return 0;
}
