#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
char a[10005];
char b[10005]; 
int c[3];

int main(){
	int flag, end,l;
    int cnt=0,cnt2=0;
    string s;
    getline(cin,s);
    l = s.size();
    for(int i=0;i < l;i++){
        if(s[i] == '6'){
     		cnt++;
     		s[i] = '9';
            if(s[i+1] != '6'){
                cnt = 0;
            }
    	}
    }
    for(int i=0;i<l;i++){
		a[i] = s[i];
		for(int j=0;j<l;j++){
			if(a[j] == '9'){
				for(int k=0;k<l;k++){
					b[k] = j;
				}
			}
		}
	}

    cout<<s<<endl;
    cout<<cnt<<endl;
    cout<<cnt2;
    
    for(int i=0;i<l;i++){
    	cout<<b[i];
	}
    return 0;
}

