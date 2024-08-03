#include <iostream>
using namespace std;

template <class DataType>
struct node{
DataType data;
node<DataType>* next;
};

template <class DataType>
class linkList{
    public:
        linkList();
        ~linkList();
        node<DataType>* reverseFindK(int k);
    private:
        node<DataType>* first;
};

template <class DataType>
linkList<DataType>::linkList()
{
    first = new node<DataType>;
    first->next = NULL;
    node<DataType>* rear = first;
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        DataType elem;
        cin>>elem;
        node<DataType>* s = new node<DataType>;
        s->data = elem;
        s->next = NULL;
        rear->next = s;
        rear = s;
    }
}
template <class DataType>
linkList<DataType>::~linkList()
{
    node<DataType>* p;
    while(first != NULL){
        p = first;
        first = first->next;
        delete p;
    }
}

template <class DataType>
node<DataType>* linkList<DataType>::reverseFindK(int k)
{
    node<DataType> *p=first,*pk=first;
    	int loc = 0;
    	while(p!=NULL&&loc<k){
    	p=p->next;
    	loc++;
    	}		
    	if(p==NULL) return NULL;
    		while(p!=NULL){
    			p=p->next;
    			pk=pk->next;
    		}
    		return pk;
}
int main()
{
    linkList<int> L;
    int k;
    cin>>k;
    node<int>* p = L.reverseFindK(k);
    if(p == NULL)
        cout<<"Not Found"<<endl;
    else
        cout<<p->data<<endl;
    L.~linkList();
    return 0;
}


