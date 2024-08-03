#include <iostream>
#include <stack>
#include <queue>
using namespace std;

stack<int> seqStack;
queue<int> cirQueue;
int n;
void init(int len)
{
    for(int i=0;i<2*len;++i){
        int elem;
        cin>>elem;
        seqStack.push(elem);
    }
}
void exchange()
{
 while(!seqStack.empty()){cirQueue.push(seqStack.top());seqStack.pop();}
 	
 	int m = cirQueue.size();
 	while(m){
 		if(m%2==0){cirQueue.push(cirQueue.front());cirQueue.pop();}
 		else {seqStack.push(cirQueue.front());cirQueue.pop();}
 		m--;
 	}
 	while(!seqStack.empty()){cirQueue.push(seqStack.top()); seqStack.pop();}
 	
 	m=cirQueue.size()/2;
 	while(m--){
 		seqStack.push(cirQueue.front());cirQueue.pop();}
 	while(!seqStack.empty()){cirQueue.push(seqStack.top());seqStack.pop();}
 	while(!cirQueue.empty()){seqStack.push(cirQueue.front());cirQueue.pop();}
}
void printStack()
{
    while(!seqStack.empty()){
        cout<<seqStack.top()<<" ";
        seqStack.pop();
    }
    cout<<endl;
}
int main()
{
    cin>>n;
    init(n);
    exchange();
    printStack();
    return 0;
}


