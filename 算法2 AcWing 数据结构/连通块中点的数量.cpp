#include<iostream>
using namespace std;

const int N = 100005;
int p[N],cnt[N];
int n,m;

//��ѯ���ڽڵ�
int find(int x){
	//·��ѹ��
	if(p[x] != x) p[x] = find(p[x]);
	return p[x]; 
} 

//�ϲ�����
void merge(int a,int b){
	//ͬһ������ ����Ҫ�ϲ� 
	if(find(a) == find(b)) return;
	// a�����ȵ�������b������ �������Ի���
	cnt[find(b)] += cnt[find(a)];
	p[find(a)] = find(b); 
} 

int main(){
	cin>>n>>m;
	
	//��ʼ�����鼯
	for(int i=1;i<=n;i++) p[i] = i,cnt[i] = 1;
	
	while(m--){
		char op[5];
		int a,b;
		cin>>op;
		if(op[0] == 'C'){
			cin>>a>>b;
			merge(a,b);
		}else if(op[1] == '1'){
			cin>>a>>b;
			cout<<(find(a) == find(b)?"Yes\n":"No\n");
		}else{
			cin>>a;
			cout<<cnt[find(a)]<<endl;
		}
	} 
	return 0;
}
