#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node*next;
};

class JosephRing{
public:
	JosephRing(int n);
	~JosephRing();
	void Joseph(int m);
private:
	Node *rear;
};

JosephRing::JosephRing(int n){
	Node *s = NULL;
	rear = new Node;
	rear->data = 1; rear->next = rear;
	for(int i=2;i<=n;i++){
		s = new Node; s->data = i;
		s->next = rear->next;
		rear->next = s;
		rear = s;
	}
}

void JosephRing::Joseph(int m){
	Node *pre = rear,*p = rear->next;
	int count = 1;
	cout<<"������˳����:";
	while(p->next != p)
	{
		if(count<m){
			pre = p; p = p->next;
			count++;
		}else{
			cout<<p->data<<"\t";
			pre->next = p->next;
			delete p;
			p = pre->next;
			count = 1;	
		}
	}
	cout<<p->data<<"\t";
	delete p;
}

int main(){
	int n,m;
	cout<<"������Լɪ�򻷵ĳ���:";
	cin>>n;
	cout<<"����������:";
	cin>>m;
	// ���������д���̫��ǰ�ˣ���c++98���в�����
	// JosephRing R{n}; 
	// R.Joseph(m);
	return 0;	
}
