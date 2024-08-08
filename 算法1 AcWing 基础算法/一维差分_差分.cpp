#include<iostream>
using namespace std;

const int N = 1e6+5;
int a[N],b[N],q[N];

void insert(int l,int r,int c){
	b[l] += c;
	b[r+1] -= c;
} 

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		// ����������
	
	for(int i=1;i<=n;i++)
		insert(i,i,a[i]);
	while(m--){
		int l,r,c;
		cin>>l>>r>>c;
		insert(l,r,c);
	} 
	for(int i=1;i<=n;i++)
		b[i] += b[i-1];
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";
	return 0; 
}
