#include<bits/stdc++.h>
using namespace std;

long Ans = 0;

void test(long row,long ld,long rd,long upperlim){
	if(row != upperlim){
		long pos = upperlim & (~(row|ld|rd));
		while(pos){
			long p = pos & (-pos);
			pos -= p;
				
			long new_ld = (ld | p) << 1;
			long new_rd = (rd | p) >> 1;
			test(row | p,new_ld,new_rd,upperlim); 
		}
	}else{
		++Ans;
	}
}

void solveNQueens(int n){
	long upperlim = (1<<n) - 1;

	
	test(0,0,0,upperlim);
	
	cout<<Ans<<endl;
}

int main(){
	int n = 8;
	solveNQueens(n);
	return 0;
}

// 八皇后问题
// 无需输入，直接输出结果 
