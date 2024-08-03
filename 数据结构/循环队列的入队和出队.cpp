#include <iostream>
using namespace std;

const int MaxSize = 5;

template <class DataType>
class cirQueue{
public:
    cirQueue();
    bool enQueue(DataType elem);
    bool deQueue();
    void printQueue();
private:
    DataType data[MaxSize];
    int front,rear;
    int flag;//区别队列空或满
};

template <class DataType>
cirQueue<DataType>::cirQueue()
{
    front = rear = MaxSize-1;
    flag = 0;
}

template <class DataType>
bool cirQueue<DataType>::enQueue(DataType elem)
{
    if ((rear + 1) % MaxSize == front) {
            return false; 
        }
        rear = (rear + 1) % MaxSize;
        data[rear] = elem;
        flag = 1;
        return true;
}

template <class DataType>
bool cirQueue<DataType>::deQueue()
{
   if (front == rear && flag == 0) {
           return false; 
       }
       front = (front + 1) % MaxSize;
       if (front == rear) {
           flag = 0; 
       }
       return true;
}

template <class DataType>
void cirQueue<DataType>::printQueue()
{
    if(front == rear && flag == 0)
        cout<<"Empty"<<endl;
    else{
        int i=(front+1)%MaxSize;
        while(i<=rear){
            cout<<data[i]<<" ";
            if(i==rear)break;
            i = (i+1)%MaxSize;
        }
        cout<<endl;
    }
}
int main()
{
    cirQueue<int> Q;
    int m,n;

    cin>>m;
    while(m--){
        int elem;
        cin>>elem;
        bool res = Q.enQueue(elem);
        if(!res) {
            cout<<"overflow"<<endl;
            return 0;
        }
    }
    cin>>n;
    while(n--){
        bool res = Q.deQueue();
        if(!res) break;
    }
    Q.printQueue();
    return 0;
}


