typedef unsigned long long ull;
ull h[N],p[N]; 

//h[k] �洢�ַ���ǰk����ĸ�Ĺ�ϣֵ
//p[k] �洢p^k mod 2^64

//��ʼ��
p[0] = 1;
for(int i=1;i<=n;i++){
	h[i] = h[i-1]*p + str[i];
	p[i] = p[i-1]*p;
} 

//�����ִ�str[L~R]�Ĺ�ϣֵ

ull get(int l,int r){
	return h[r] - h[l-1] * p[r-l+1];
} 
