#include<iostream>
using namespace std;

const int N = 100005;
int p[N];
int n,m;

//��ѯ���ڽڵ� 
int find(int x){
	// ·��ѹ��
	if(p[x] != x) p[x] = find(p[x]);
	return p[x]; 
}

//�ϲ�����
void merge(int a,int b){
	//ͬһ������ ����Ҫ�ϲ� 
	if(find(a) == find(b)) return;
	p[find(a)] = find(b);
} 

int main(){
	cin>>n>>m;
	//��ʼ�����鼯
	for(int i = 1;i<=n;i++) p[i] = i;
	
	while(m--){
		char op[2];
		int a,b;
		
		cin>>op>>a>>b;
		if(op[0] == 'M') merge(a,b);
		else cout<<(find(a) == find(b)?"Yes":"No")<<endl;
	}
}
