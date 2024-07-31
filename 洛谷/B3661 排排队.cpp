#include<bits/stdc++.h>
using namespace std;

int n,m;
int i=0,j=0;
long long a[10006];
long long b[10006];

int method(int x){
	if(x%2==0){
		a[i]=x;
		i++;
		return 0;	
	}else{
		b[j]=x;
		j++;
		return 0;
	}
}

int main(){

	cin>>n;
	while(n--){
		cin>>m;
		method(m);
	}
	for(int l=0;l<j;l++){
		cout<<b[l]<<" ";
	}
	cout<<"\n";
	for(int k=0;k<i;k++){
		cout<<a[k]<<" ";
	} 

	return 0;
} 
