#include<bits/stdc++.h>
using namespace std;

bool check1(int a,int b,int c){
	int cnt=0;
	if(a<60){
		cnt++;
	}
	if(b<60){
		cnt++;
	}
	if(c<60){
		cnt++;
	}
	if(cnt<=1){
		return 1;
	}
	return 0;
}

bool check2(int a,int b,int c,int d,int e,int f){
	double sum1=0,sum2=0,ans;
	sum1=a*d+b*e+c*f;
	sum2=d+e+f;
	ans=sum1/sum2;
	if(ans>=60){
		return 1;
	}else{
		return 0;
	}
}

int output(int a){
	if(a=1){
		cout<<"PASS"<<endl;
	}else{
		cout<<"FALL"<<endl;
	}
}

int main(){
	double a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int abc=check1(a,b,c);
	int abc2=check2(a,b,c,d,e,f);
	cout<<abc<<" "<<abc2;
	return 0;
}
