#include<bits/stdc++.h>
using namespace std;

int n,k,a[50];
char s[50];

struct node{
	int v;
	bool exl;
	int c[50];
}cut[50][10],ans[50];

node culc(int l,int r){ // 取数操作 
	node e;
	e.v = r-l+1;
	e.exl = true;
	for(int i=1;i<=e.v;i++){
		e.c[i] = a[r-i+1];
	}
	return e;
}

node mul(node e1,node e2){ // 高精度乘法
 	node emul;
 	emul.exl = true;
 	emul.v = e1.v+e2.v-1;
 	for(int i=1;i<=emul.v;i++)
 		emul.c[i]=0;
 	
 	for(int i=1;i<=e1.v;i++)
 		for(int j=1;j<=e2.v;j++)
 			emul.c[i+j-1] += e1.c[i] * e2.c[j];
 	
 	int q=0;
 	for(int i=1;i<=emul.v;i++){
 		emul.c[i] += q;
 		q = emul.c[i]/10;
 		emul.c[i] %= 10;
	 }
	 while(q>0){
	 	emul.c[++emul.v] = q%10;
	 	q/=10;
	 }
	 return emul;
}

node Max(node e1,node e2){
	if(!e1.exl || e1.v < e2.v)
		return e2;
	if(!e2.exl || e2.v < e1.v)
		return e1;
	
	for(int i=e1.v;i>=1;i--){
		if(e1.c[i] > e2.c[i])
			return e1;
		else if(e2.c[i] > e1.c[i])
			return e2;
	}
	return e1;
}

int main(){
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++)
		a[i+1] = s[i] - '0';
	
	for(int i=1;i<=n;i++){
		ans[i].exl = false;
		for(int j=1;j<=k;j++)
			cut[i][j].exl = false;
	}
	
	for(int i=1;i<n;i++){
		cut[i][1] = culc(1,i);
		for(int j=2;j<=k;j++){
			for(int fr=j-1;fr<i;fr++){
				if(cut[fr][j-1].exl)
					cut[i][j] = Max(cut[i][j],mul(cut[fr][j-1],culc(fr+1,i)));	
			}
		}
		if(cut[i][k].exl){
			ans[i] = mul(cut[i][k],culc(i+1,n));
		}
	}
	node lastans;
	lastans.exl = false;
	for(int i=1;i<n;i++){
		node tmp = Max(ans[i],lastans);
		lastans = tmp; 
	}
	for(int i=lastans.v;i>=1;i--)
		cout<<lastans.c[i];
	return 0;
} 
