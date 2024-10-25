int n,m;     // n���������m������� 
int dist[N]; // dist[x]�洢1��x�����·����
bool f;

struct Edge{ // ��a��ʾ���㣬b��ʾ��㣬w��ʾ�ߵ�Ȩ�� 
	int a,b,w;
}edges[M];

// ��1��n�����·���룬����޷���1�ߵ�n���򷵻�-1

int  bellman_ford(){
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	
	// �����n�ε�����Ȼ���ɳ����ǲ���ʽ����˵������һ��������n+1�����·��
	// �ɳ���ԭ��·�������ٴ���������ͬ�ĵ㣬˵��ͼ�д��ڸ�Ȩ��· 
	// ����������n����
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a = edges[j].a,b = edges[j].b,w = edges[j].w;
			if(dist[b]>dist[a]+w)
				dist[b] = dist[a]+w;
		}
	} 
	if(dist[n]>0x3f3f3f3f/2) return -1;
	return dist[n];
} 
