#include<iostream>
using namespace std;

int a,b,c;

int main()
{
	cin>>a>>b>>c;
	if(a+b>c&&a+c>b&&b+c>a)
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
