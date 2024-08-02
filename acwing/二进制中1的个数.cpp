#include<iostream>
using namespace std;

//源代码 int lowbit(x) 报错， x was not declare,后改 int x, 运行正常 

int lowbit(int x){
	return x & -x; 
}

int main(){
	int n;
	cin>>n;
	while(n--)
	{
		int x;
		cin>>x;
		
		int res = 0;
		while(x)
		{
			x -= lowbit(x);
			res++;
		}
		cout<<res<<' ';
	}
	return 0;
}
