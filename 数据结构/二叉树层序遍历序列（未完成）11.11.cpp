#include<queue>
#include<cstdlib>
#include<iostream>
using namespace std;

template<class DataType>

struct BiNode{
	DataType data;
	BiNode<DataType> *lchild,*rchild;
};

template<class DataType>
class BiTree{
	public:
		BiTree(){root = PreCreate(root);};
		~BiTree(){Release(root);};
		void LeverOrder();
	private:
		BiNode<DataType> *root;
		BiNode<DataType> *PreCreate(BiNode<DataType>*bt);
		void Release(BiNode<DataType>*bt);
};

template<class DataType>
BiNode<DataType>*BiTree<DataType>::PreCreate(BiNode<DataType>*bt){
	
}
