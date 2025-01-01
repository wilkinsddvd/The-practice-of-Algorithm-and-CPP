#include<bits/stdc++.h>
#define N 105
using namespace std;
 
int n;
int p[N], m[N][N], s[N][N];
 
void printTrace(int i, int j)//根据最优子结构确定
{
	if (i == j)
	{
		printf("A%d", i);
		return;
	}
	printf("(");
	printTrace(i, s[i][j]);
	printTrace(s[i][j] + 1, j);
	printf(")");
}
 
int main()
{
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		scanf("%d", &p[i]);
	
	if (n == 1)//特判
	{
		printf("0\n");
		printf("(A1)\n");
		return 0;
	}
	
	for (int i = 1; i <= n; i++)
		m[i][i] = 0;
	for (int r = 2; r <= n; r++)//r表示对角线的序号
	{
		for (int i = 1; i <= n - r + 1; i++)//当前斜线的元素个数的范围
		{
			int j = i + r - 1;//i与j,r的关系可以通过二维上三角求出
			//初始化记录
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
			s[i][j] = i;
 
			for (int k = i + 1; k < j; k++)
			{
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
 
	printf("%d\n", m[1][n]);
	printTrace(1, n);
	printf("\n");
 
	return 0;
}

// 测试用例
// 6 30 35 15 5 10 20 25
// 六个矩阵，除了第一个矩阵的行列要全部乘一次后，以后的五个矩阵只需要乘列，就可以算出最优子结构 以及所需要的次数
// 预期输出
// 15125
// ((A1(A2A3))((A4A5)A6)) 
