#include<bits/stdc++.h>
using namespace std;

template<class T>
void mySwap(T&a,T&b){
	T temp = a;
	a = b;
	b = temp;
}

void test01(){
	int a=10;
	int b=20;
	char c = 'c';
	mySwap(a,b);
}

template<class T>

void func(){
	cout<<"funcµ÷ÓÃ"<<endl;
} 

void test02(){
	func<int>();
}

int main(){
	test01();
	test02();
	system("pause");
	return 0;
}
