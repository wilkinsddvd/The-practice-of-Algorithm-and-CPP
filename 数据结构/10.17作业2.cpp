#include<cstring>
#include<iostream>
#include<string>
using namespace std;

void getNext(string T,int length,int next[])
{
	
}

int Index_KMP(string S,int slen,string T,int tLen,int pos,int next[])
{
	
}

void show(int *arr,int len)
{
	for(int i=0;i<len;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(){
	string S,T;
	getline(cin,S);
	getline(cin,T);
	int SLength,TLength;
	SLength = S.length();
	TLength = T.length();
	int *p = new int[TLength];
	getNext(T,TLength,p);
	cout<<Index_KMP(S,SLength,T,TLength,0,p)<<endl;
	show(p,TLength);
	return 0;
}
