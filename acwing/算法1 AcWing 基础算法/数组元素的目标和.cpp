#include<iostream>

using namespace std;
const int N = 100005;
int a[N],b[N];

int main(){
	int n,m,x;
	cin>>n>>m>>x;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int j=0;j<m;j++)	cin>>b[j];
	
	int i=0,j=m-1;
	while(i<n && j>=0){
		// �ʹ���x, j��ǰ�ƶ� 
		while(a[i] + b[j]>x)	j--;
		// ��С��x, i����ƶ� 
		while(a[i] + b[j]<x)	i++;
		if(a[i] + b[j] == x){
			cout << i <<" "<<j;
			break;
		}
	}
	return 0;
}
 
