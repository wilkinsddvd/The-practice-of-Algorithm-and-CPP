#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010;
int h[N],e[N],ne[N],idx;
int q[N],in[N],hh,tt=-1;
int n,m;

void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

bool topsort(){
	// ���������Ϊ0�ĵ����
	for(int i=1;i<=n;i++)
		if(!in[i]) q[++tt] = i;
	
	while(hh <= tt){
		int t = q[hh++];
		for(int i=h[t];i!=-1;i=ne[i]){
			int j =e[i];
			// ȥһ���� ���-1
			in[j]--;
			// ���Ϊ0 ���
			if(!in[j]) q[++tt] = j; 
		} 
	} 
	return tt == n-1;
}

int main(){
	cin>>n>>m;
	
	memset(h,-1,sizeof h);
	
	while(m--){
		int a,b;
		cin>>a>>b;
		add(a,b);
		// ��b�����+1
		in[b]++; 
	}
	if(topsort()){
		// �������о��Ƕ��е�˳��
		for(int i=0;i <= tt;i++) 
			cout<<q[i]<<' ';
		cout<<endl; 
	}else{
		cout<<-1;
	}
	return 0;
}
