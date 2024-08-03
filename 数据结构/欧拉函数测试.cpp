#include<bits/stdc++.h>
using namespace std;

const int MAX = 1024;
int N;
int p[MAX],phi[MAX];

int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		p[i]=1;
		phi[i]=i; 
	}
	p[1]=0;
	for(int i=2;i<=N;i++){
		if(p[i]){
			for(int j=i*i;j<=N;j+=i){
				p[j]=0;
			} 
		}
		for(int i=2;i<=N;i++;){
			if(p[i]){
				for(int j=i)
			}
		}
	}
}
