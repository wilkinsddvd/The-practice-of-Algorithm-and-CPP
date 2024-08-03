#include<iostream>
using namespace std;

typedef int DataType;
typedef struct node{
	DataType data;
	node* next;
}node;
node*first;

void init()
{
	first = new node;
	first->next = NULL;
	node* rear = first;
	int length;
	cin>>length;
	for(int i=0;i<length;++i){
		DataType elem;
		cin>>elem;
		node* s = new node;
		s->data = elem;
		s->next =NULL;
		rear->next = s;
		rear = s; 
	} 
}

void deleteList(DataType minK,DataType maxk)
{
	node* p = first->next;
    node* pre = first;
    while (p != NULL) {
        if (p->data >minK && p->data < maxk) {
            pre->next = p->next;
            delete p;
            p = pre->next;
        }
        else {
            pre = p;
            p = p->next;
        }
    }
}

void show()
{
	node*p = first->next;
	if(p==NULL) cout<<"Empty";
	while(p!=NULL){
		cout<<p->data<<" ";
		p = p->next;10	}
	cout<<endl;
}
 
int main()
{
	init();
	DataType mink,maxk;
	cin>>mink>>maxk;
	deleteList(mink,maxk);
	show();
	return 0;
}
