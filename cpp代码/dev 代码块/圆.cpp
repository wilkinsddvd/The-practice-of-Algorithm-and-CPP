#include<bits/stdc++.h>
using namespace std;

const double  PI=3.14;


class Circle{
	public:
		int m_r;
		double calculateZC(){
			return 2*PI*m_r;
		}
}; 

int main(){
	Circle c1;
	cin>>c1.m_r;
	cout<<"Բ���ܳ�Ϊ��"<<c1.calculateZC()<<endl;
	system("pause");
	return 0;
}
