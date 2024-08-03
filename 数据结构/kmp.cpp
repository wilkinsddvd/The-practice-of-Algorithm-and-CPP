#include<bits/stdc++.h>
using namespace std;

int KMP(char*t,char*p)
{
	int i=0;
	int j=0;
	while(i<(int)strlen(t)&& j<(int)strlen(p))
	{
		if(j==-1||t[i]==p[j]){
			i++;
			j++;
		}
		else
			j=next[j];
	} 
	if(j==strlen(p))
		return i-j;
	else
		return -1;
}

void getNext(char*p,int*next){
	next[0]=-1;
	int i=0,j=-1;
	while(i<(int)strlen(p))
	{
		if(j==-1||p[i]==p[j]){
			++i;
			++j;
			next[i]=j;
		}
		else
			j=next[j];
	}
}
