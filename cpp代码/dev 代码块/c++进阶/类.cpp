#include<bits/stdc++.h>
using namespace std;

class Person{
	public:
		string m_Name;
	protected:
		string m_Car;
	private:
		int m_Password;
	public:
		void func(){
			string m_Name,m_Car;
			int m_Password;
			cin>>m_Name>>m_Car>>m_Password;
			cout<<m_Name<<endl;
			cout<<m_Car<<endl;
			cout<<m_Password<<endl; 
		}
};

int main(){
	Person p;
	p.m_Name="ÀîËÄ";
	system("pause");
	return 0;
}
