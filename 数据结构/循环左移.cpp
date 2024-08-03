#include <iostream>
using namespace std;
void reverseArr(int A[],int start,int rear){
int i,j;
	for(i=start,j=rear;i<j;i++,j--)
	{
		int temp=A[i];
		A[i]=A[j];
		A[j]=temp;
	}
}

void leftCir(int A[],int n,int k){
   if(k<=0 || k>=n)
        cout<<"ERROR"<<endl;
    else{
    reverseArr(A,0,k-1);
    reverseArr(A,k,n-1);
    reverseArr(A,0,n-1);
    }
}
void show(int A[],int n){
    for(int i=0;i<n;++i)
        cout<<A[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,p;
    cin>>n>>p;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    leftCir(a,n,p);
    show(a,n);
    return 0;
}


