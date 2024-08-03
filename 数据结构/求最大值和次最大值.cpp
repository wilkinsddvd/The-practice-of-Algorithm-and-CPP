#include <iostream>

using namespace std;
void getMax(int A[],int n,int &fMax,int &sMax){
    int i;
    	fMax = -32767;
    	sMax = -32767;
    	for(i=0;i<n;i++)
    	{
    		if(A[i]>fMax)
    		{
    			sMax = fMax;
    			fMax = A[i];
    		}
    		else if(A[i] > sMax)
    			sMax = A[i];
    	}
}
int main()
{
    int n,maxV,nMax;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    getMax(a,n,maxV,nMax);
    cout<<maxV<<" "<<nMax<<endl;
    return 0;
}


