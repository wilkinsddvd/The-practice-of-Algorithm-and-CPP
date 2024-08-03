#include<iostream>
using namespace std;

const int MaxSize = 100;

template<typename DataType>
class SeqList{
public:
	SeqList();
	SeqList(DataType a[],int n);
	~SeqList();
	int length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i,DataType x);
	DataType Delete(int i);
	int Empty();
	void PrintList();
private:
	DataType data[MaxSize];
	int length; 
};

int main(){
	int r[5] = {1,2,3,4,5},i,x;
	SeqList<int>L(r,5);
	cout<<"��ǰ���Ա������Ϊ:";
	L.PrintList();
	try{
		L.Insert(2,8);
		cout<<"ִ�в�������������Ϊ:";
		L.PrintList(); 
	}catch(char*str){
		cout<<str<<endl;
	}
	cout<<"��ǰ���Ա�ĳ���Ϊ:"<<L.length()<<endl;
	cout<<"��������ҵ�Ԫ��ֵ:";
	cin>>x;
	i = L.Locate(x);
	if(0==i) cout<<"����ʧ��"<<endl;
	else cout<<"Ԫ��"<<x<<"��λ��Ϊ:"<<i<<endl;
	try{
		cout<<"������Ҫɾ���ڼ���Ԫ��:";
		cin>>i;
		x = L.Delete(i);
		cout<<"ɾ����Ԫ����"<<x<<"��ɾ��������Ϊ:";
		L.PrintList();
	}catch(char*str){
		cout<<str<<endl;
	}
	return 0;
}
