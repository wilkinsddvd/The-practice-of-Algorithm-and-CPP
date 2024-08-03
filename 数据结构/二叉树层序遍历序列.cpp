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
	DataType ch;
	cin >> ch;
	if(ch == '#') bt = NULL;
	else{
		bt = new BiNode<DataType>;
		bt->data = ch;
		bt->lchild = PreCreate(bt->lchild);
		bt->rchild = PreCreate(bt->rchild);
	}
	return bt;
}

template<class DataType>
void BiTree<DataType>::Release(BiNode<DataType>*bt){
	if(bt == NULL) return;
	else{
		Release(bt->lchild);
		Release(bt->rchild);
		bt = NULL;
		delete bt;
	}
}

template<class DataType>
void BiTree<DataType>::LeverOrder(){
	if(root == NULL) return;
	queue<BiNode<DataType>*> q;
	q.push(root);
	while(!q.empty()){
		BiNode<DataType>* p = q.front();
		q.pop();
		cout << p->data;
		if(p->lchild) q.push(p->lchild);
		if(p->rchild) q.push(p->rchild);
	}
}

int main(){
	BiTree<char> biTree;
	biTree.LeverOrder();
	biTree.~BiTree();
	return 0;
}
