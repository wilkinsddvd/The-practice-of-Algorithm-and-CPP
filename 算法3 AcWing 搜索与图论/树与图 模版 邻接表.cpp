//�ڽӱ�

// ����ÿ����k����һ���������洢k���п����ߵ��ĵ㣬h[k] �洢����������ͷ���

int h[N],e[N],ne[N],idx;

// ���һ���� a->b

void add(int a,int b){
	e[idx] = b,ne[idx] = h[a],h[a] = idx++;
}

// ��ʼ��
idx = 0;
memset(h,-1,sizeof h); 
