#include<cstring>
#include<iostream>
#include<string>
using namespace std;

void getNext(string T,int length, int next[])//计算next函数值
{
    int m = 0, k = -1;
   	next[0] = -1;
   	while (m < length)
   	{
   		if (k == -1 || T[m] == T[k])
   			next[++m] = ++k;
   		else
   			k = next[k];
   	}
}

int Index_KMP(string S, int sLen,string T,int tLen, int pos, int next[])//KMP算法
{
    	int i = 0;
    	int j = 0;
    	while ((S[i] != '\0') && (T[j] != '\0')) {
    		if (S[i] == T[j]) {
    			i++;
    			j++;
    		}
    		else {
    			j = next[j];
    		}
    		if (j == -1) {
    			i++;
    			j++;
    		}
    	}
    	if (T[j] == '\0') {
    		return i - j + 1;
    	}
    	else return 0;
}
void show(int *arr,int len)
{
    for(int i=0;i<len;++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    string S,T;
    getline(cin,S);
    getline(cin,T);
    int SLength,TLength;
	SLength=S.length();
	TLength=T.length();
    int *p=new int[TLength]; //生成T的next数组
    getNext(T,TLength,p);
    cout<<Index_KMP(S,SLength,T,TLength,0,p)<<endl;
    show(p,TLength);
    return 0;
}

