#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int a[N];

int BinarySearch(int a[],int left,int right,int k){
	if(left<=right){
		while(left<=right){
		int mid = (left + right)/2;
		if(k == a[mid]) return mid;
		if(k < a[mid])  cout <<a[mid]; 	return BinarySearch(a,left,mid+1,k);
		if(k > a[mid]) 	cout<<a[mid];	return BinarySearch(a,mid+1,right,k);
		}
	} 
	else
		cout<<"no";
	return -1;
}

int main(){
	int n,k;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>k;
	BinarySearch(a,0,a.length-1,k);
	return 0;
}	
