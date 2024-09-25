#include<bits/stdc++.h>
using namespace std;

#define N 1003
int Hash[N] = {0};
struct myqueue{
	int data[N];
	int head,rear;
	bool init(){
		Q.data = (int *)malloc(N * sizeof(int));
		if(!Q.data)	return false;
		head = rear = 0;
		return true;
	}
	int size(){
		return (rear - head + N) % N;
	}
	bool empty(){
		if(size() == 0)	return true;
		else	return false;
	}
	bool push(int e){
		if((rear+1) % N == head)	return false;
		data[rear] = e;
		rear = (rear + 1) % N;
		return true;
	}
	bool pop(int &e){
		if(head == rear)	return false;
		e = data[head];
		head = (head + 1) % N;
		return true;
	}
	int front(){
		return data[head];
	}
}Q;

int main(){
	Q.init();
	int m,n;	cin>>m>>n;
	int cnt = 0;
	while(n--){
		int en;	cin>>en;
		if(!Hash[en]){
			++cnt;
			Q.push(en);
			Hash[en] = 1;
			while(Q.size()>m){
				int tmp;	Q.pop(tmp);
				Hash[tmp] = 0;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
} 
