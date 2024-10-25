#include<iostream>
using namespace std;

const int N = 100010;
int h[N],n,m,len;

void down(int i){
	int t = i;
	// i�����ҽڵ���Сֵ����(������ڵĻ�)
	if(i*2 <= len && h[i*2] < h[t]) t = i*2;
	if(i*2 +1 <= len && h[i*2+1] < h[t]) t = i*2+1;
	if(i!=t){
		swap(h[i],h[t]);
		down(t);
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		cin>>h[i];
	len = n;
	// ��ʼ����O(n)�ĸ��Ӷ�
	for(int i=n/2;i;i--) down(i);
	
	while(m--){
		cout<<h[1]<<" ";
		h[1] = h[len];
		len--;
		down(1);
	} 
	return 0;
}
