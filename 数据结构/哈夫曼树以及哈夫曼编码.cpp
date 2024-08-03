#include<iostream>
#include<string.h>
using  namespace  std;
struct  HTNode{
        int  weight;
        int  parent,lchild,rchild;
};
class  HuffmanTree{
public:
        HuffmanTree(int  W[],int  n);
      ~HuffmanTree();
        void  Select(HTNode*  HT,int  len,int  &i1,int  &i2);
        void  CreatHuffmanCode(  );
        void  showHuffmanCode(int  i);
private:
        int  nodeNum;
        HTNode*  HT;//�洢��������
        char**  HTC;//�洢����������
};

HuffmanTree::HuffmanTree(int  W[],int  n){
        nodeNum  =  n;
        HT  =  new  HTNode[2*n  -1];
        //��ʼ��
        for(int  i=0;i  <  2*nodeNum  -1;i++){
                HT[i].lchild  =  -1;
                HT[i].rchild  =  -1;
                HT[i].parent  =-1;
        }
        for(int  i=0;i  <  nodeNum;i++)
                HT[i].weight  =  W[i];
        //������������
        for(int  k  =  nodeNum;k  <  2*nodeNum-1;k++){
                int  i1,i2;
                Select(HT,k,i1,i2);
                HT[k].weight  =  HT[i1].weight  +  HT[i2].weight;
                HT[i1].parent  =  k;
                HT[i2].parent  =  k;
                HT[k].lchild  =  i1;
                HT[k].rchild  =  i2;
        }
}
HuffmanTree::~HuffmanTree(){
                HT  =  NULL;
        delete  HT;
        HTC  =  NULL;
        delete  []HTC;
}
void  HuffmanTree::Select(HTNode*  HT,int  len,int  &i1,int  &i2){
	int min1 = INT_MAX;
    int min2 = INT_MAX;
    i1 = -1;
    i2 = -1;
    for (int i = 0; i < len; ++i) { 
        if (HT[i].parent == -1) { 
            if (HT[i].weight < min1) { 
                min2 = min1;
                i2 = i1;
                min1 = HT[i].weight;
                i1 = i;
            }
            else if (HT[i].weight < min2) { 
                min2 = HT[i].weight;
                i2 = i;
            }   
        }
    }
}
//���кշ�������                                                                                                //  CreatHuffmanTree
void  HuffmanTree::CreatHuffmanCode(  )
{
        //��Ҷ�ӵ���������ÿ���ַ��ĺշ������룬�洢�ڱ����HC��
        int  i,start,c,f;
        HTC=new  char*[nodeNum];                                                                  //����n���ַ������ͷָ��ʸ��
        char  *cd=new  char[nodeNum];                                                        //������ʱ��ű���Ķ�̬����ռ�
        cd[nodeNum-1]='\0';                                                                        //���������
        for(i=0;i<nodeNum;++i)
        {                                                                                                    //����ַ���շ�������
                start=nodeNum-1;                                                                    //start��ʼʱָ����󣬼����������λ��
                c=i;
                f=HT[i].parent;                                                          //fָ����c��˫�׽��
                while(f!=-1)
                {                                                                                            //��Ҷ�ӽ�㿪ʼ���ϻ��ݣ�ֱ�������
                        --start;                                                                    //����һ��start��ǰָһ��λ��
                        if(HT[f].lchild==c)
                                cd[start]='0';                                                //���c��f�����ӣ������ɴ���0
                        else
                                cd[start]='1';                                                  //���c��f���Һ��ӣ������ɴ���1
                        c=f;
                        f=HT[f].parent;                                                  //�������ϻ���
                }                                                                                            //�����i���ַ��ı���
                HTC[i]=new  char[nodeNum-start];                                          //  Ϊ��i  ���ַ��������ռ�
                strcpy(HTC[i],  &cd[start]);                                        //����õı������ʱ�ռ�cd���Ƶ�HC�ĵ�ǰ����
        }
        delete  cd;                                                                                //�ͷ���ʱ�ռ�
}
void  HuffmanTree::showHuffmanCode(int  i)
{
                cout<<HTC[i-1]<<endl;
}
int  main()
{
        int  n;
        cin>>n;
        int  W[n];
        for(int  i=0;i<n;i++)
                cin>>W[i];
        HuffmanTree  huffmanTree(W,n);
        huffmanTree.CreatHuffmanCode();
        int  i;
        cin>>i;
        if(i<1  ||  i>  n)
                cout<<"NO"<<endl;
        else
                huffmanTree.showHuffmanCode(i);
        huffmanTree.~HuffmanTree();
        return  0;
}
