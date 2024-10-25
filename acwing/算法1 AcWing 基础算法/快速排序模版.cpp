#include<iostream>
using namespace std;

const int N=1e5+10;
int n;
int q[N];

void quick_sort(int q[],int l,int r){
	int mid = q[(l+r)/2];
	int i = l,j=r;
	int tmp;
	while(i<j){
		while(q[i] < mid)
			i++;
		while(q[j] > mid)
			j--;
		if(i <= j){
			tmp = q[i];
			q[i] = q[j];
			q[j] = tmp;
			i++;
			j--;
		} 
	}
	if(l < j)
		quick_sort(q,l,j);
	if(i < r)
		quick_sort(q,i,r);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>q[i];
	quick_sort(q,0,n-1);
	for(int i=0;i<n;i++)
		cout<<q[i]<<" ";
	return 0;
} 
