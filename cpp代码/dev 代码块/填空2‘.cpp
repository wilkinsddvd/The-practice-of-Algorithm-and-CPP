#include  <iostream>
using  namespace  std;
const  int  MaxSize = 100;
/*��Ԫ��ṹ��*/
template  <class  DataType>
struct  element {
    int  row, col;  //����Ԫ�ص��С���
    DataType  item;  //����Ԫ��ֵ
};
 
template  <class  DataType>
class  SparseMatrix {
public:
    SparseMatrix();
    void  printMatrix();
    void  printSparseMatrix();
    void  trans2(SparseMatrix<DataType>& B);
private:
    element<DataType>  data[MaxSize];  //�洢��Ԫ���
    int  mu, nu, tu;  //�ֱ��ʾϡ����������������������Ԫ�صĸ���
};
/*��Ԫ��˳���Ĺ���*/
template  <class  DataType>
SparseMatrix<DataType>::SparseMatrix()
{
    int  row, col, num;
    cin >> row >> col >> num;  //ϡ����������������
    mu = row;
    nu = col;
    tu = num;  //�洢ʱ��0��ʼ
    for (int k = 0; k < num; ++k) {
        int  i, j, temp;
        cin >> i >> j >> temp;
        data[k].row = i;
        data[k].col = j;
        data[k].item = temp;
    }
}
 
/*ϡ�����Ĵ�ӡ*/
template  <class  DataType>
void  SparseMatrix<DataType>::printMatrix()
{
    int a[100][100];
    int i, j;
    for (i = 0; i < mu; i++) {
        for (j = 0; j < nu; j++) {
            a[i][j] = 0;
        }
    }
    for (int k = 0; k <tu; k++) {
        a[data[k].row-1][data[k].col-1] = data[k].item;
    }
    for (i = 0; i < mu; i++) {
        for (j = 0; j < nu; j++) {
            cout<<a[i][j]<<"     ";
        }
        cout << endl;
    }
 
}
 
 
int  main()
{
    SparseMatrix<int>  A;
    A.printMatrix();
    return  0;
}
