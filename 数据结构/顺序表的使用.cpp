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
	cout<<"当前线性表的数据为:";
	L.PrintList();
	try{
		L.Insert(2,8);
		cout<<"执行插入操作后的数据为:";
		L.PrintList(); 
	}catch(char*str){
		cout<<str<<endl;
	}
	cout<<"当前线性表的长度为:"<<L.length()<<endl;
	cout<<"请输入查找的元素值:";
	cin>>x;
	i = L.Locate(x);
	if(0==i) cout<<"查找失败"<<endl;
	else cout<<"元素"<<x<<"的位置为:"<<i<<endl;
	try{
		cout<<"请输入要删除第几个元素:";
		cin>>i;
		x = L.Delete(i);
		cout<<"删除的元素是"<<x<<"，删除后数据为:";
		L.PrintList();
	}catch(char*str){
		cout<<str<<endl;
	}
	return 0;
}
