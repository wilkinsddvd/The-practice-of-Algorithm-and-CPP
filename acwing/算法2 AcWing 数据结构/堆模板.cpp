//�����дһ����?
// 1.����һ����            heap[++size] = x; up(size);
// 2.�󼯺ϵ��е���Сֵ    heap[1];
// 3.ɾ����Сֵ            heap[1] = heap[size]; size--; down(1);
// 4.ɾ������һ��Ԫ�� 	   heap[k] = heap[size]; size--; down(k); up(k);
// 5.�޸�����һ��Ԫ��      heap[k] = x; down(k); up(k);
//
//

void heap_swap(int a,int b){
	swap(ph[hp[a]],ph[hp[b]]);
	swap(hp[a],hp[b]);
	swap(h[a],h[b]);
}

// ���µ��� ���Ԫ�ط�����

void down(int i){
	int t = i;
	// i�����ҽڵ���Сֵ����(������ڵĻ�)
	if(i*2 <= len && h[i*2] < h[t]) t = i * 2;
	if(i*2 + 1 <= len && h[i*2+1] < h[t]) t = i*2+1;
	if(i!=t){
		heap_swap(i,t);
		down(t);
	}
} 

// ���ϵ��� С��Ԫ�ط�����

void up(int i){
	while(i/2 && h[i] < h[i/2]){
		heap_swap(i,i/2);
		i /= 2;
	}
} 

//��ʼ���� O(n)�ĸ��Ӷ�
for(int i=n/2;i;i--) down(i); 
//
//
//
//
//
//
// 
