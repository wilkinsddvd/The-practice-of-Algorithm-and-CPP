#include  <iostream>
using  namespace  std;
void  saddlePoint(int** A, int  n, int  m)
{
    int i, j;
    int max[10] = { 0 }, min[10] = { 0 };//���ÿ����Сֵ��ÿ�����ֵ
    int MIN, MAX;
    for (i = 1; i <=n; i++) {//ÿ�б���
        MIN = A[i][1];//ÿ�е�һ��
        for (j = 1; j <=m; j++) {//ÿ�б���
            if (MIN > A[i][j]) {
                MIN = A[i][j];
            }
        }
        min[i] = MIN;//��ÿ����Сֵ������������
    }
    for (j = 1; j <=m; j++) {//ÿ�б���
        MAX = A[1][j];//ÿ�е�һ��
        for (i = 1; i <=n; i++) {//����ÿһ��
            if (MAX < A[i][j]) {
                MAX = A[i][j];
            }
        }
        max[j] = MAX;//��ÿ�����ֵ������������
    }
    int flag = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (A[i][j] == min[i] && A[i][j] == max[j]) {//����Ѱ��ͬʱ�����ֵ
                flag = 1;
                cout << A[i][j] << " " << i << " " << j << endl;
            }
        }
        
    }
    if (flag == 0) cout << "No answer";
}
int  main()
{
    int  n, m;
    cin >> n >> m;
    int** arr = new  int* [n + 1];
    for (int i = 0; i <= n + 1; ++i)
        arr[i] = new  int[m + 1];
 
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> arr[i][j];
 
    saddlePoint(arr, n, m);
    return  0;
}
