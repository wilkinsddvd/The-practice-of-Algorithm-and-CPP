#include <iostream>
using namespace std;

void saddlePoint(int** A,int n,int m)
{
   int i, j;
       int max[10] = { 0 }, min[10] = { 0 };//存放每行最小值，每列最大值
       int MIN, MAX;
       for (i = 1; i <=n; i++) {
           MIN = A[i][1];
           for (j = 1; j <=m; j++) {
               if (MIN > A[i][j]) {
                   MIN = A[i][j];
               }
           }
           min[i] = MIN;
       }
       for (j = 1; j <=m; j++) {
           MAX = A[1][j];
           for (i = 1; i <=n; i++) {
               if (MAX < A[i][j]) {
                   MAX = A[i][j];
               }
           }
           max[j] = MAX;
       }
       int flag = 0;
       for (i = 1; i <= n; i++) {
           for (j = 1; j <= m; j++) {
               if (A[i][j] == min[i] && A[i][j] == max[j]) {
                   flag = 1;
                   cout << A[i][j] << " " << i << " " << j << endl;
               }
           }
           
       }
       if (flag == 0) cout << "No answer";
}
int main()
{
    int n,m;
    cin>>n>>m;
    int** arr = new int*[n+1];
    for(int i=0;i<= n+1;++i)
        arr[i] = new int[m+1];

    for(int i=1;i<= n;++i)
        for(int j=1;j<= m;++j)
            cin>>arr[i][j];

    saddlePoint(arr,n,m);
    return 0;
}


