// �������Ĵ������� ȱһ�� �ܲ����� 

#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010,M=2*N;

int h[N],e[M],ne[M],idx;
int n;
int ans = N;

bool st[N];

void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

int dfs(int u){
	st[u] = true;
	
	int sum = 1,res = 0;
	for(int i=h[u];i!=-1;i = ne[i]){
		int j = e[i];
		if(!st[j]){
			int s = dfs(j);
			sum += s;
			// ��ǰ�ڵ����������ֵ
			res = max(s,res); 
		}
	}
	// ɾ���õ���������ֵ��������ֵ
	res = max(res,n-sum);
	
	// ���ı�֤ɾ���õ��ʣ�ಿ�ֵ��������ֵ��С
	ans = min(ans,res);
	
	return sum; 
}

int main(){
	cin>>n;
	memset(h,-1,sizeof h);
	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b),add(b,a);
		// ����һ�� 
	}
	// ͼ���еı��
	dfs[1];
	
	cout<<ans<<endl;
	return 0; 
}
