#include<iostream>
#include<string>

using namespace std;

int main(){
	string str,substr;
	int pos;
	getline(cin,str);
	getline(cin,substr);
	cin>>pos;
	
	size_t found = str.find(substr,pos);
	if(found!=string::npos){
		cout<<found+1<<endl;
	}
	else{
		cout<<0<<endl;
	}
	return 0;
} 
