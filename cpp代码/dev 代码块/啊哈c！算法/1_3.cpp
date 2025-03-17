#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[100],i,j,t,n;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
		
	for(i=1;i<=n-1;i++){
		for(j=1;j<=n-i;j++){
			if(a[j] < a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	
	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
		
	getchar(); getchar();
	return 0;
}

// 输出     1000 999 100 50 22 15 8 6 1 0
// 要求输出 0  1 6 8 15 22 50 100 999 1000 
