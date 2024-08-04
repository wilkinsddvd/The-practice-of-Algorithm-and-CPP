#include<bits/stdc++.h>
using namespace std;

const int N = 510, inf = 0x3f3f3f3f;
int g[N][N], d[N];
bool st[N];
int n,m;

int prim(){
	memset(d,0x3f,sizeof d);
	int res = 0;
	
	for(int i=0;i<n;i++){
		int t = -1;
		for(int j=1;j<=n;j++)
			if(!st[j] && (t  == -1 || d[t] > d[j])) t = j;
	
		// ������ǵ�һ���� �����ҵ�����С��ľ���Ϊinf �򲻹�����С������
		
		if(i && d[t] == inf) return inf;
		
		// ������ǵ�һ���� d[t]��ʾ��ǰ����ĳһ�����ߵĳ���
		
		if(i) res += d[t];
		
		// �ȼ��� �ٸ��� ���� t=j ʱ �Ի����³��� 
		for(int j=1;j<=n;j++) d[j] = min(d[j],g[t][j]);
		st[t] = true; 
	}
	return  res;
}

int main(){
	cin>>n>>m;
	memset(g,0x3f,sizeof g);
	
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b] = g[b][a] = min(g[a][b],c);
	}
	int t = prim();
	
	if(t == inf) 
		puts("impossible");
	else
		cout<<t<<endl;
	return 0;
}
