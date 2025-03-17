#include<bits/stdc++.h>
using namespace std;

bool my_less(int i,int j){
	return (i<j);
}

bool my_greater(int i,int j){
	return (i>j);
} 

int main(){
	vector<int>a = {3,7,2,5,6,8,5,4};
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
	return 0;
}
