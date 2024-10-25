//(1)������ �ڽӱ�
// h[] �洢ͷָ�� ��ʼ��Ϊ-1 
// e[] �洢�ڵ��ֵ 
//ne[] �洢��һ��Ԫ�ص�ָ��

int h[N],e[N],ne[N],idx;

// ���ϣ���в���һ����

void insert(int x){
	//����д�Ƿ�ֹxΪ����
	int k = (x%N+N)%N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
} 

// �ڹ�ϣ���в�ѯĳ�����Ƿ����

bool find(int x){
	int k = (x%N+N)%N;
	for(int i=h[k];i != -1;i = ne[i])
		if(e[i] == x)
			return true;
	return false;
} 

//��2������Ѱַ��

int h[N];

//���x�ڹ�ϣ���� ����x���±� ���x���ٹ�ϣ���� ����xӦ�ò����λ��

int find(int x){
	int t = (x%N+N)%N;
	while(h[t] != NULL && h[t] != x){
		t++;
		if(t==N) t = 0;
	}
	return t;
} 

