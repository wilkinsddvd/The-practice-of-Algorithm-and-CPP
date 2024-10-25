#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

void zhuan(int n,int r){
	if(n==0)
		return ;
	int m=n%r;
	
	if(m<0)
		m-=r,n+=r;
	
	if(m>=10)
		m='A'+m-10;
	else
		m+='0';
	
	zhuan(n/r,r);
	
	printf("%c",m);
	return ;
} 

int main(){
	int n,r;
	string ans="";
	cin>>n>>r;
	cout<<n<<"=";
	zhuan(n,r);
	printf("(base%d)",r);
	return 0;
}
