#include <iostream>
using namespace std;
const int MaxSize = 100;

/* 三元组结构体 */
template <class DataType>
struct element
{
    int row, col;  // 非零元素的行、列
    DataType item; // 非零元素值
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
    element<DataType> data[MaxSize]; // 存储三元组表
    int mu, nu, tu;                  // 分别表示稀疏矩阵的行数、列数、非零元素的个数
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
