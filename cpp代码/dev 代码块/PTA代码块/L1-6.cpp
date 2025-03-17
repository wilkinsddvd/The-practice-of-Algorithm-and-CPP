#include<bits/stdc++.h>
using namespace std;

int a[105];

int re(int x){
	int a,b,c,d,e,f,g,h,sum=0;
	a = x%10;
	b = x/10%10;
	c = x/100%10;
	d = x/1000%10;
	e = x/10000%10;
	f = x/100000%10;
	g = x/1000000%10;
	h = x/10000000%10;
	sum = a+b+c+d+e+f+g;
	return sum;
}

int main(){
	int n,ans,t1,t2,t3,t4,t5,t6,t7,t8,ans1, ans2, ans3, ans4, ans5, ans6, ans7,ans8;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t1 = a[i] * 2;
		t2 = a[i] * 3;
		t3 = a[i] * 4;
		t4 = a[i] * 5;
		t5 = a[i] * 6;
		t6 = a[i] * 7;
		t7 = a[i] * 8;
		t8 = a[i] * 9;
		ans1 = re(t1);
		ans2 = re(t2);
		ans3 = re(t3);
		ans4 = re(t4);
		ans5 = re(t5);
		ans6 = re(t6);
		ans7 = re(t7);
		ans8 = re(t8);
		if(ans1 == ans2 && ans2 == ans3 && ans3 == ans4 && ans4 == ans5 && ans5 == ans6 && ans6 == ans7 && ans7 == ans8)	
			cout<<ans1<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
