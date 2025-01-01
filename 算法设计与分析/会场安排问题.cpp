#include<bits/stdc++.h>
using namespace std;

const int n = 11;
struct meeting{
	int B;
	int E;
};

int main(){
	int n;
	cin>>n;
	meeting M[n];
	for(int i=0;i<n;i++){
		cin>>M[i].B>>M[i].E;
	}
//	meeting M[n] ={{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,14}};
	for(int i=0;i<n;i++)
		for(int j=0;j<n-i-1;j++)
			if(M[j].E > M[j+1].E){
				meeting T;
				T = M[j];	M[j] = M[j+1];	M[j+1] = T;
			}
	int allowedTime = 0;
	for(int i=0,j=0;i<n;i++){
		if(M[i].B > allowedTime){
			j++;
			cout<<i+1<<" ";
			allowedTime = M[i].E;
		}
	} 
}

//11
//1 4
//3 5
//0 6
//5 7
//3 8
//5 9
//6 10
//8 11
//8 12
//2 13
//12 14
