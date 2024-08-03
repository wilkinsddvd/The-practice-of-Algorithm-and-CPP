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
	cout<<"出环的顺序是:";
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
	cout<<"请输入约瑟夫环的长度:";
	cin>>n;
	cout<<"请输入密码:";
	cin>>m;
	// 这里有两行代码太超前了，用c++98运行不出来
	// JosephRing R{n}; 
	// R.Joseph(m);
	return 0;	
}
