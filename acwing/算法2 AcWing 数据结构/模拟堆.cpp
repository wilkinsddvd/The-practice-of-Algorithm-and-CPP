#include<iostream>
using namespace std;

const int N = 100005;
//h[N] �洢���е�ֵ,h[1]�ǶѶ�,x���������2x,�Ҷ�����2x+1
//ph[k] �洢��k������ĵ��ڶ��е��±�
//hp[k] �洢�����±���k�ĵ��ǵڼ�������� 
//len  ��ʾ�ѵĴ�С 
//m ��ʾ��ǰԪ���ǵڼ�������� 

int h[N],hp[N],ph[N],len,m;

void heap_swap(int a,int b){
	swap(ph[hp[a]],ph[hp[b]]);
	swap(hp[a],hp[b]);
	swap(h[a],h[b]);
}

//���µ���

void down(int i){
	int t = i;
	if(2*i <= len && h[2*i] < h[t]) t =2*i;
	if(2*i + 1 <= len && h[2*i+1] < h[t]) t = 2*i+1;
	if(t!=i){
		heap_swap(i,t);
		down(t);
	}
} 

//���ϵ���

void up(int i){
	while(i/2 && h[i] < h[i/2]){
		heap_swap(i,i/2);
		i /= 2;
	}
} 

int main(){
	int n,k,x;
	string op;
	cin>>n;
	
	while(n--){
		cin>>op;
		if(op == "I"){
			cin>>x;
			len++;
			m++;
			ph[m] = len, hp[len] = m;
			h[len] = x;
			up(len);
		}else if(op == "PM"){
			cout<<h[1]<<endl;
		}else if(op == "DM"){
			heap_swap(1,len);
			len--;
			down(1);
		}else if(op == "D"){
			cin>>k;
			//��ȡ��k������Ԫ�ص��±�
			k = ph[k];
			heap_swap(k,len);
			len--;
			down(k),up(k); 
		}else{
			cin>>k>>x;
			//��ȡ��k������Ԫ�ص��±�
			k = ph[k];
			h[k] = x;
			down(k),up(k); 
		}
	}
	return 0;
}
