#include<iostream>
using namespace std;

const int N = 100005;
int cnt[N],a[N];
int n;

int main(){
	cin>>n;
	int res = 0;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int i=0,j=0;i<n;i++){
		cnt[a[i]]++;
		while(cnt[a[i]]>1)	cnt[a[j++]]--;
		res = max(res,i-j+1);
	}
	cout<<res;
	return 0;
} 
