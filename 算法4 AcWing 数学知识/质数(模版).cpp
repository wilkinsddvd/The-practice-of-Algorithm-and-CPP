#include<bits/stdc++.h>
using namespace std;

// �Գ����ж�����
bool is_prime(int x){
	if(x<2) return false;
	// ֻ��ö��һ���� ʹ�� i<= x/i ʱ�临�Ӷ�Ϊ ��n
	for(int i=2;i<=x/i;i++)
		if(x%i == 0)
			return false;
	return true; 
} 

// �Գ����ֽ�������
void divide(int n){
	for(int i=2;i<=n/i;i++){
		if(n%i == 0){
			int cnt = 0;
			while(n%i == 0){
				n /= i;
				cnt++; 
			}
			cout<<i<<cnt<<endl;
		}
	}
	// �����������
	if(n > 1) cout<<n<<1<<endl;
	cout<<endl; 
} 

int main(){
	
}
