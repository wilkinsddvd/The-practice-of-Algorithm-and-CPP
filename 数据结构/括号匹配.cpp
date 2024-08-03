#include<iostream>

using namespace std;

bool match(string _str)
{
	char S[100];
	int top=-1,i;
	for(i=0;_str[i]!='\0';i++)
	{
		if(_str[i]=='('||_str[i]=='['||_str[i]=='{') S[++top] = _str[i];
		else if(_str[i]==')' && top>-1 && S[top]=='(') top--;
		else if(_str[i]==']' && top>-1 && S[top]=='[') top--;
		else if(_str[i]=='}' && top>-1 && S[top]=='{') top--;
		else return false;
	}
	if(top==-1) return true;
	if(top>-1) return false;
	return true;
}

int main()
{
	string str;
	cin>>str;
	if(match(str))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}



