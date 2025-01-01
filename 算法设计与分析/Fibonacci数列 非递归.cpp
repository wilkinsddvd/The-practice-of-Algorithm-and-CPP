#include<iostream>
using namespace std;
unsigned long long F[1000033];
int main(){
	int n;
	cin>>n;
	F[1]=1;
	F[2]=1;
	for(int i=3;i<=n;i++){
		F[i]=F[i-1]+F[i-2];
	}
    cout<<F[n]<<endl; 
	return 0;
}
