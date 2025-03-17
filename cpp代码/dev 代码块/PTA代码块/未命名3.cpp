#include<bits/stdc++.h>
using namespace std;

int main(){
    double a,b,result;
    cin>>a>>b;
    if(a==0){
    	result = 0;
    	if(b<0){
    		cout<<a<<"/"<<"("<<b<<")"<<"=";
    		cout<<fixed<<setprecision(2)<<result;
    		return 0;
		}
    	cout<<a<<"/"<<b<<"=";
    	cout<<fixed<<setprecision(2)<<result;
    	return 0;
	} 
    if(b!=0){
    	if(b<0){
    		result = a/b;
    		cout<<a<<"/"<<"("<<b<<")"<<"=";
    		cout<<fixed<<setprecision(2)<<result;
    		return 0;
		}
        result = a/b;
        cout<<a<<"/"<<b<<"=";
        cout<<fixed<<setprecision(2)<<result;
        return 0;
    }
    cout<<"Error";
    return 0;
}
