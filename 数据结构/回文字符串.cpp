#include <iostream>
using namespace std;

bool judge(string str){
int i , j;
for( i = 0, j = str.size()-1;i<j;i++,j--)
    if(str[i]!=str[j]) return false;
return true;
}
int main()
{
    string s;
    getline(cin,s);
    bool res=judge(s);
    if(res)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}


