#include <iostream>
using namespace std;

const int MaxSize=100;
typedef int DataType;
DataType data[MaxSize];
int length;

void reverseList( )
{
    	int i,k,temp;
    	for(i=0,k=length-1;i<k;i++,k--)
    	{
    		temp = data[i];
    		data[i] = data[k];
    		data[k] = temp;
    	}	
}
void show()
{
    for(int i=0;i<length;++i)
        cout<<data[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>length;
    for(int i=0;i<length;++i)
        cin>>data[i];
    reverseList();
    show();
    return 0;
}


