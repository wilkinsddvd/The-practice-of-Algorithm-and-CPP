// ����������⣬��Ҫ�����������ַ�����������ǳ������� 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int h,m;
	scanf("%d %d",&h,&m);
	if(h>12){
		h-=12;
	}
	printf("%d:%d pm",h,m);
	return 0;
} 
