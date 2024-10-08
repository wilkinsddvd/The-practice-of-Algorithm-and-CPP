#include<bits/stdc++.h>
using namespace std;

int n,c,x[100005];
bool check(int dis){
	int cnt = 1,place = 0;
	for(int i=1;i<n;++i){
		if(x[i] - x[place] >= dis){
			cnt++;
			place = i;
		}
	}
	if(cnt >= c)	return 1;
	else	return 0;
}

int main(){
	cin>>n>>c;
	for(int i=0;i<n;i++)	cin>>x[i];
	sort(x,x+n);
	int left = 0,right = x[n-1] - x[0];
	int ans = 0;
	while(left < right){
		int mid = left + (right - left)/2;
		if(check(mid)){
			ans = mid;
			left = mid + 1;
		}
		else	right = mid;
	}
	cout<<ans;
	return 0;
}
