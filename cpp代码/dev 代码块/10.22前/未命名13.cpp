#include<iostream>
using namespace std;

int main()
{
	int a,b;
	cin>>a>>b;
	if(a>=0&&a<=100&&b>=1&&b<=100)
	{
		cout<<a/b<<" "<<a%b;
	}
	return 0;
}
