#include<iostream>
#include<stack>
#include<queue>
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

void exchang()
{
	
}

void printStack()
{
	while(!seqStack.empty){
		cout<<seqStack.top()<<" ";
		seqStack.pop();
	}
}
