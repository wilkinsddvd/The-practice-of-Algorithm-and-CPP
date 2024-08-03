#include <iostream>
using namespace std;

typedef int DataType;
typedef struct node{
    DataType data;
    node* next;
}node;

//尾插法构造单链表
void init(node*&first,int len)
{
    first = NULL;
    node* rear;
    for(int i=0;i<len;++i){
        DataType elem;
        cin>>elem;
        node* s = new node;
        s->data = elem;
        s->next = NULL;
        if(first == NULL){
            first = s;
            rear = first;
        }
        else{
           rear->next = s;
           rear = s;
        }
    }
}
//八进制A加八进制B，结果存在链表A中
void add(node* A,node* B)
{
     int carry = 0;  
        node *p = A, *q = B, *pre = NULL;
        while(p != NULL && q != NULL){
            int sum = p->data + q->data + carry;
            p->data = sum % 8;  
            carry = sum / 8;  
            pre = p;
            p = p->next;
            q = q->next;
        }
        if(q != NULL){
            pre->next = q;
            p = q;
        }
        while(p != NULL && carry != 0){
            int sum = p->data + carry;
            p->data = sum % 8;
            carry = sum / 8;
            pre = p;
            p = p->next;
        }
        if(carry != 0){
            node* s = new node;
            s->data = carry;
            s->next = NULL;
            pre->next = s;
        } 
}

void reverseList(node* &first)
{
   	node *prev = NULL;
       node *current = first;
       while (current != NULL) {
           node *nextNode = current->next;
           current->next = prev;
           prev = current;
           current = nextNode;
       }
       first = prev;
}
void show(node* first)
{
    node* p = first;
    if(p == NULL) cout<<"Empty";
    else{
        while(p != NULL){
            cout<<p->data;
            p = p->next;
        }
        cout<<endl;
    }
}
int main()
{
    node*A,*B;
    int aLen,bLen;
    cin>>aLen;
    init(A,aLen);
    cin>>bLen;
    init(B,bLen);

    reverseList(A);
    reverseList(B);

    add(A,B);
    reverseList(A);
    show(A);
    return 0;
}


