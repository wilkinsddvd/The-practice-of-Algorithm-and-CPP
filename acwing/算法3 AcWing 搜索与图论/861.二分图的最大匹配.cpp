#include<bits/stdc++.h>
using namespace std;

const int N = 510,M = 100010;
int h[N],e[M],ne[M],idx;
int match[N],n1,n2,m;
bool st[N];

void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool find(int x){
	for(int i = h[x];i!=-1;i=ne[i]){
		int j = e[i];
		// û�з��ʹ�
		if(!st[j]){
			st[j] = true;
			// û��ƥ�� ���߿���ƥ��������
			if(!match[j] || find(match[j])){
				match[j] = x;
				return true;
			}
		} 
	}
	return false;
}

int main(){
	cin>>n1>>n2>>m;
	memset(h,-1,sizeof h);
	while(m--){
		int u,v;
		cin>>u>>v;
		add(u,v);
	}
	
	int res = 0;
	
	for(int i=1;i<=n1;i++){
		// ÿ��ģ��ƥ���Ԥ��������ǲ�һ���� 
		// ����ÿ��ģ�ⶼҪ��ʼ��
		memset(st,false,sizeof st);
		if(find(i))
			res++; 
	}
	cout<<res;
	return 0;
}
