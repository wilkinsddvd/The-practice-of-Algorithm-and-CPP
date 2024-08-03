#include<iostream>
using namespace std;
const int MaxSize = 100;

template<class DataType>
struct element{
	int row,col;
	DataType item;
};

template<class DataType>
class SparseMatrix{
	public:
		SparseMatrix();
		void printMatrix();
		void printSparseMatrix();
		void trans2(SparseMatrix<DataType>&B);
	private:
		element<DataType>data[MaxSize];
		int mu,nu,tu;
};

template<class DataType>
SparseMatrix<DataType>::SparseMatrix(){
	int row,col,num;
	cin>>row>>col>>num;
	mu = row;
	nu = col;
	tu = num;
	for(int k=0;k<num;++k) {
		int i,j,temp;
		cin>>i>>j>>temp;
		data[k].row = i;
		data[k].col = j;
		data[k].item = temp;
	}
} 

template<class DataType>
void SparseMatrix<DataType>::printMatrix(){
	
}

int main()
{
	SparseMatrix<int>A;
	A.printMaxtrix();
	return 0;
}
