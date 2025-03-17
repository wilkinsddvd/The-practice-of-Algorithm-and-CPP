#include<bits/stdc++.h>
using namespace std;

struct stu{
	int id;
	int c,m,e;
	int sum;
}st[305];

bool cmp(stu a,stu b){
	if(a.sum > b.sum)	return 1;
	else if(a.sum < b.sum)	return 0;
	else{
		if(a.c > b.c)	return 1;
		else if(a.c < b.c)	return 0;
		else{
			if(a.id > b.id)	return 0;
			else	return 1;
		}
	}
}

int main(){
	int n;	cin>>n;
	for(int i=1;i<=n;i++){
		st[i].id = i;
		cin>>st[i].c>>st[i].m>>st[i].e;
		st[i].sum = st[i].c + st[i].m + st[i].e;
	}
	sort(st+1,st+n+1,cmp);
	for(int i=1;i<=5;i++)	
		cout<<st[i].id<<" "<<st[i].sum<<endl;
	return 0;
}
