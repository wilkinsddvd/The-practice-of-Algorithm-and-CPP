#include<iostream>
#include<algorithm>
using namespace std;

const int N =100010;
int a[N],n;
int t[N];
long long ans;

void merge_sort(int l,int r,int a[]){
	if(l >= r)return;
	int mid = l+r>>1;
	merge_sort(l,mid,a);
	merge_sort(mid+1,r,a);
	int i=l,j=mid+1,g=0;
	while(i <= mid && j <= r){
		if(a[i] > a[j]) t[g++] = a[j++],ans += mid-i+1;
		else t[g++] = a[i++];
	}
	while(i <= mid) t[g++] = a[i++];
	while(j <= r) t[g++] = a[j++];
	
	i=l,j=0;
	while(i <= r){
		a[i++] = t[j++];
	}
} 

int main(){
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	ans = 0;
	merge_sort(0,n-1,a);
	cout<<ans;
	return 0;
}
