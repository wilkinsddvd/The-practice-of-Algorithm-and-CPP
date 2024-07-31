#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int a){
	if(a>=118){
		return 1;
	}
	return 0;
}

bool check1(int a){
	if(a>=63){
		return 1;
	}
	return 0;
}

bool check2(int a){
	if(a>=41){
		return 1;
	}
	return 0;
}

bool check3(int a){
	if(a<41){
		return 1;
	}
	return 0;
}

int jieguo(int a,int b,int c,int d){
	int ans;
	if(a>=1){
		ans=10;
		return ans;
	}
	if(b>=4){
		ans=8;
		return ans;
	}
	if(c>=4){
		ans=3;
		return ans;
	}
	if(d>=1){
		ans=1;
		return ans;
	}
}

int main(){
	ll a,b,c,d,e,f,g,h;
	int cnt1=0,cnt2=0,cnt3=0,cnt4=0,ans;
	cin>>a>>b>>c>>d>>e>>f>>g>>h;
	if(check(a)){
		cnt1++;
	}
	if(check(b)){
		cnt1++;
	}
	if(check(c)){
		cnt1++;
	}
	if(check(d)){
		cnt1++;
	}
	if(check(e)){
		cnt1++;
	}
	if(check(f)){
		cnt1++;
	}
	if(check(g)){
		cnt1++;
	}
	if(check(h)){
		cnt1++;
	}
	
	if(check1(a)){
		cnt2++;
	}
	if(check1(b)){
		cnt2++;
	}
	if(check1(c)){
		cnt2++;
	}
	if(check1(d)){
		cnt2++;
	}
	if(check1(e)){
		cnt2++;
	}
	if(check1(f)){
		cnt2++;
	}
	if(check1(g)){
		cnt2++;
	}
	if(check1(h)){
		cnt2++;
	}	
	
	if(check2(a)){
		cnt3++;
	}
	if(check2(b)){
		cnt3++;
	}
	if(check2(c)){
		cnt3++;
	}
	if(check2(d)){
		cnt3++;
	}
	if(check2(e)){
		cnt3++;
	}
	if(check2(f)){
		cnt3++;
	}
	if(check2(g)){
		cnt3++;
	}
	if(check2(h)){
		cnt3++;
	}	

	if(check3(a)){
		cnt4++;
	}
	if(check3(b)){
		cnt4++;
	}
	if(check3(c)){
		cnt4++;
	}
	if(check3(d)){
		cnt4++;
	}
	if(check3(e)){
		cnt4++;
	}
	if(check3(f)){
		cnt4++;
	}
	if(check3(g)){
		cnt4++;
	}
	if(check3(h)){
		cnt4++;
	}	
	
	ans=jieguo(cnt1,cnt2,cnt3,cnt4);
	cout<<ans;
	return 0;
		
}
