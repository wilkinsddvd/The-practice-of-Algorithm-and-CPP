#include <iostream>
using namespace std;
void split(int A[],int n){
    int i=0,j=n-1;
       while(i<j){
           while(A[i]%2!=0 && i<j){ 
               i++;
           }
           while(A[j]%2==0 && i<j){
               j--;
           }
           if(i<j){ 
               int temp = A[i];
               A[i] = A[j];
               A[j] = temp;
           }
       }
}
void show(int A[],int n){
    for(int i=0;i<n;++i)
        cout<<A[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    split(a,n);
    show(a,n);
    return 0;
}


