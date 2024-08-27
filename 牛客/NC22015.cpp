#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){
	int re;
	if(a>b)
		re = a;
	else
		re = b;
	return re;
}

int min(int a,int b){
	int re;
	if(a<b)
		re = a;
	else
		re = b;
	return re;
}

int main(){
	int a,b,c,ma,mi;
	cin>>a>>b>>c;
	ma = max(a,b);
	ma = max(ma,c);
	mi = min(a,b);
	mi = min(mi,c);
	cout<<"The maximum number is : "<<ma<<'\n';
	cout<<"The minimum number is : "<<mi;
	return 0; 

}
