#include <iostream>
using namespace std;
const int MaxSize = 100;

/* ��Ԫ��ṹ�� */
template <class DataType>
struct element
{
    int row, col;  // ����Ԫ�ص��С���
    DataType item; // ����Ԫ��ֵ
};

template <class DataType>
class SparseMatrix
{
public:
    SparseMatrix();
    void printMatrix();
    void printSparseMatrix();
    void trans2(SparseMatrix<DataType> &B);

private:
    element<DataType> data[MaxSize]; // �洢��Ԫ���
    int mu, nu, tu;                  // �ֱ��ʾϡ����������������������Ԫ�صĸ���
};


template <class DataType>
SparseMatrix<DataType>::SparseMatrix()
{
    int row, col, num;
    cin >> row >> col >> num; 
    mu = row;
    nu = col;
    tu = num; 
    for (int k = 0; k < num; ++k)
    {
        int i, j, temp;
        cin >> i >> j >> temp;
        data[k].row = i;
        data[k].col = j;
        data[k].item = temp;
    }
}

template <class DataType>
void SparseMatrix<DataType>::printMatrix()
{
    DataType matrix[mu][nu] = {0};

    for (int k = 0; k < tu; k++)
    {
        int row = data[k].row;
        int col = data[k].col;
        DataType item = data[k].item;
        matrix[row-1][col-1] = item;
    }
    for (int i = 0; i < mu; i++)
    {
        for (int j = 0; j < nu; j++)
        {
            cout << matrix[i][j] << "     ";
        }
        cout << endl;
    }
}

int main()
{
    SparseMatrix<int> A;
    A.printMatrix();
    return 0;
}
