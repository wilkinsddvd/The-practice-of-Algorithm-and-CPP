#include<bits/stdc++.h>
using namespace std;

const int N = 100010;

int h[N],e[N],ne[N],w[N],idx;
int q[N],hh,tt=-1;
int d[N];
bool st[N];
int n,m;

void add(int a, int b, int c){
	e[idx] = b,w[idx] = c,ne[idx] = h[a],h[a] = idx++;
} 

int spfa(){
	memset(d,0x3f,sizeof d);
	d[1] = 0;
	q[++tt] = 1;
	st[1] = true;
	
	while(hh <= tt){
		int t = q[hh++];
		st[t] = false;
		for(int i=h[t];i!=-1;i=ne[i]){
			int j = e[i];
			if(d[j] > d[t] + w[i]){
				d[j] = d[t] + w[i];
				if(!st[j]){
					q[++tt] = j;
					st[j] = true;
				}
			}
		}
	}
	return d[n]; 
}

int main(){
	cin>>n>>m;
	
	memset(h,-1,sizeof h);
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
	}
	int t = spfa();
	
	// ����Ҫ d[n] > 0x3f3f3f3f / 2 ������
	// ��Ϊ�����ﶼ���������µ��ĵ�
	// ������ bellman-ford �㷨��δ���µĵ�ͬ�����߸��µ����
	if(t == 0x3f3f3f3f) puts("impossible");
	else
		cout<<t<<endl;
	return 0; 
}
