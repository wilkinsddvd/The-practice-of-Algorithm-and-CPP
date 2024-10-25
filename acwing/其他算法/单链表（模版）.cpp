const int N = 100010;

int e[N],ne[N],idx =1;

void insert(int k,int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx++;
}

void remove(int k,int x)
{
	ne[k] = ne[ne[k]];
}
