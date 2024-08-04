//����Ѱַ�� ��Χ2-3��

//�ַ�����ϣ
//����˼�룺 ���ַ�������P��������P�ľ���ֵ��131��13331��ȡ������ֵ�ĳ�ͻ���ʵ�
//С���ɣ� ȡģ������2^64������ֱ����unsigned long long�洢������Ľ������ȡģ�Ľ��
//ע�⣺ �ַ�����1��λ�ÿ�ʼ�档ǰlλ�ַ����Ĺ�ϣֵ��h[l] 
//ǰrλ�ַ����Ĺ�ϣֵ��h[r]���� l~r֮���ַ����������˵㣩�Ĺ�ϣֵ���Ա�ʾΪ��
//h[l �� r] = h[1 �� r]-h[1 �� ! - 1] * Pr-l+1

#include<iostream>
#include<cstring>

using namespace std;

const int N = 200003,null = 0x3f3f3f3f;//��Χ2-3�� ����
int h[N];
int n;

//���x�ڹ�ϣ���� ����x���±�  ���x���ڹ�ϣ���� ����xӦ�ò����λ��

int find(int x){
	int k = (x%N+N)%N;
	
	while(h[k] != null && h[k] != x){
		k++;
		if(k == N) k = 0;
	}
	return k;
} 

int main(){
	cin>>n;
	//memset ���ֽڸ�ֵ ���λ
	memset(h,0x3f,sizeof h);
	char op[2];
	int x;
	while(n--){
		cin>>op>>x;
		int k = find(x);
		if(op[0] == 'I') h[k] = x;
		else cout<<(h[k]!=null?"Yes\n":"NO\n");
	} 
	return 0;
}
