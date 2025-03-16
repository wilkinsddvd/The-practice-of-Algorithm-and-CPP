#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int length = s.length();
    for(int i=0;i<s.length();i++){
        if(i==0){
            s[i] -= 32;
        }
        if(i%2==0){
            s[i] -= 32;
        }
    }
    cout<<s;
    return 0;
}