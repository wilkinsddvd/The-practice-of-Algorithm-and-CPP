#include<bits/stdc++.h>
using namespace std;

bool check(int a1,int a2,int b1,int b2){
	if((a1+1==b1 && a2+2==b2) || (a1+1==b1 && a2-2==b2)){
		return 1;
	}
	if((a1-1==b1 && a2+2==b2) || (a1-1==b1 && a2-2==b2)){
		return 1;
	}
	if((a1+2==b1 && a2+1==b2) || (a1+2==b1 && a2-1==b2)){
		return 1;
	}
	if((a1-2==b1 && a2+1==b2) || (a1-2==b1 && a2-1==b2)){
		return 1;
	}
	return 0;
}

int nextstep(int a1,int a2){
	
}

int main(){
	int a1,a2,b1,b2,c1,c2,ans1,ans2,ans3,ans4,ans5,ans6,ans7,ans8,ans9,ans10,ans11,ans12,ans13,ans14,ans15,ans16;
	int d1,d2,e1,e2,f1,f2,g1,g2,h1,h2,i1,i2,j1,j2,k1,k2;
	cin>>a1>>a2>>b1>>b2>>c1>>c2;
	
	d1=c1+1,d2=c2+2,e1=c1+1,e2=c2-2;
	f1=c1-1,f2=c2+2,g1=c1-1,g2=c2-2;
	h1=c1+2,h2=c2+1,i1=c1+2,i2=c2-1;
	j1=c1-2,j2=c2+1,k1=c1-2,k2=c2-1;

	ans1=check(d1,d2,a1,a2),ans2=check(d1,d2,b1,b2);
	ans3=check(e1,e2,a1,a2),ans4=check(e1,e2,b1,b2);
	ans5=check(f1,f2,a1,a2),ans6=check(f1,f2,b1,b2);
	ans7=check(g1,g2,a1,a2),ans8=check(g1,g2,b1,b2);
	ans9=check(h1,h2,a1,a2),ans10=check(h1,h2,b1,b2);
	ans11=check(i1,i2,a1,a2),ans12=check(i1,i2,b1,b2);
	ans13=check(j1,j2,a1,a2),ans14=check(j1,j2,b1,b2);
	ans15=check(k1,k2,a1,a2),ans16=check(k1,d2,k1,b2);	 
	if((ans1 && ans2) || (ans3 && ans4) || (ans5 && ans6) || (ans7 && ans8) || (ans9 && ans10) || (ans11 && ans12) || (ans13 && ans14) || (ans15 && ans16)){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}
