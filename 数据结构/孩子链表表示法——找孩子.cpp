#include<cstdlib>
#include<iostream>
using  namespace  std;
struct  CTNode{
        int  child;
        CTNode  *next;
};
template<class  DataType>
struct  CBNode{
        DataType  data;
        CTNode  *firstChild;
};
template<class  DataType>
class  ChildLink{
public:
        ChildLink(int  num);
        ~ChildLink();
        bool  findChild(DataType  elem,int  i,DataType  &value);
        int  findPos(DataType  elem);
private:
        CBNode<DataType>*  arrayPtr;
        int  nodeNUm;
};

  
  template<class  DataType>
  ChildLink<DataType>::ChildLink(int  num){
          arrayPtr  =  new  CBNode<DataType>[num+1];
          CTNode**arrayRear  =  new  CTNode*[num+1];//β��
          nodeNUm  =  num;
          for(int  i  =  1;i<=  num;i++){
                DataType  temp;
                cin>>temp;
                arrayPtr[i].data  =  temp;
                arrayPtr[i].firstChild  =  NULL;
          }
          int  row;
          cin>>row;
        for(int  i  =  0;i  <  row;i++){
                DataType  parent,child;
                cin>>parent>>child;
                int  parLoc  =  findPos(parent);
                int  chiLoc  =  findPos(child);
                if(arrayPtr[parLoc].firstChild  ==  NULL){//��һ������
                        arrayPtr[parLoc].firstChild  =  new  CTNode;
                        arrayPtr[parLoc].firstChild  ->child  =  chiLoc;
                        arrayPtr[parLoc].firstChild  ->next  =  NULL;
                        arrayRear[parLoc]  =  arrayPtr[parLoc].firstChild  ;
                }
                else{
                        CTNode*  s=  new  CTNode;//β��
                        s->child  =  chiLoc;
                        s->next  =  NULL;
                        arrayRear[parLoc]->next  =  s;
                        arrayRear[parLoc]  =  s;
                }
        }
  }

template<class  DataType>
ChildLink<DataType>::~ChildLink(){
        CTNode*  first  =  NULL;
        for(int  i=1;i<=nodeNUm;i++){
                first  =  arrayPtr[i].firstChild;
                while(first  !=  NULL){
                        arrayPtr[i].firstChild  =  first->next;
                        delete  first;
                        first  =  arrayPtr[i].firstChild;
                }
        }
}
  //����Ԫ��elem�ĵ�i������
template<class  DataType>
bool  ChildLink<DataType>::findChild(DataType  elem,int  i,DataType  &value){
    int pos = findPos(elem); 
    if (pos != 0) {
        CTNode* node = arrayPtr[pos].firstChild; 
        int count = 1;
        while (node != nullptr && count < i) { 
            node = node->next;
            count++;
        }
        if (node != nullptr) {
            value = arrayPtr[node->child].data; 
            return true;
        }
    }
    return false;      
}
  template<class  DataType>
  int  ChildLink<DataType>::findPos(DataType  elem){
          for(int  i  =  1;i  <=  nodeNUm;i++)
                if(arrayPtr[i].data  ==  elem)  return  i;
          return  0;//����ʧ��
  }
  

int  main()
{
        int  n;
        cin>>n;
        ChildLink<char>  childLink(n);
        char  value,elem;
        int  i;
        cin>>elem;
        cin>>i;
        if(childLink.findChild(elem,i,value))
                cout<<value<<endl;
        else
                cout<<"NO"<<endl;
        childLink.~ChildLink();
        return  0;
}
