#include<bits/stdc++.h>
using namespace std;

int main(){
	int cnt=0,n;
	cin>>n;
	n += 1;
	while(n--){
		if(n%2==0){
			cnt -= n;
		}else{
			cnt += n;
		}
	}
	cout<<cnt;
	return 0;
}
