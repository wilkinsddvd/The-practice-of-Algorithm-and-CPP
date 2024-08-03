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

template<typename DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
	if(n>MaxSize) throw"�����Ƿ�";
	for(int i=0;i<n;i++)
		data[i] = a[i];
	length = n; 
}

template<typename DataType>
void SeqList<DataType>::PrintList()
{
	for(int i=0;i<length;i++)
		cout<<data[i]<<"\t";
	cout<<endl;
 } 
 
 template<typename DataType>
 DataType SeqList<DataType>::Get(int i)
 {
 	if(i<1||i>length) throw"����λ�÷Ƿ�";
 	else return data[i-1];
 }
 
 template<typename DataType>
 int SeqList<DataType>::Locate(DataType x)
 {
 	for(int i=0;i<length;i++)
 		if(data[i] == x) return i+1;
 	return 0;
 }
 
template<typename DataType>
void SeqList<DataType>::Insert(int i,DataType x)
{
	if(length = MaxSize) throw"����";
	if(i<1 || i > length+1) throw"����λ�ô���";
	for(int j=length;j>=i;j--)
		data[j] = data[j-1];
	data[i-1] = x;
	length++; 
}

template<typename DataType>
DataType SeqList<DataType>::Delete(int i)
{
	DataType x;
	if(length == 0) throw"����";
	if(i<1||i>length) throw"ɾ��λ�ô���";
	x = data[i-1];
	for(int j=i;j<length;j++)
		data[j-1] = data[j];
	length--;
	return x; 
 } 

int main(){
	
}
