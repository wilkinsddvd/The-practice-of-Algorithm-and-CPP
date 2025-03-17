#include<bits/stdc++.h>
using namespace std;

#define MAX 100
#define MIN -100
int a[MAX];
unsigned long ulrand(){
	return(
		(((unsigned long)rand()<<24)& 0xFF000000ul)
		|(((unsigned long)rand()<<12)& 0x00FFF000ul)
		|(((unsigned long)rand())	&0x00000FFFul));
}

int bin_search(int *a,int n,int x){
	int left = 0,right = n;
	while(left < right){
		int mid = left + (right-left)/2;
		if(a[mid] >= x)	right = mid;
		else	left = mid + 1;
	}
	return left;
}

int main(){
	int n = MAX;
	srand(time(0));
	while(1){
		for(int i=0;i<n;i++)
			a[i] = ulrand() % (MAX - MIN + 1) + MIN;
		sort(a,a+n);
		int test = ulrand() % (MAX - MIN + 1) + MIN;
		int ans = bin_search(a,n,test);
		int pos = lower_bound(a,a+n,test) - a;
		if(ans == pos)	cout<<"!";
		else{
			cout<<"wrong";
			break;
		} 
	} 
}
