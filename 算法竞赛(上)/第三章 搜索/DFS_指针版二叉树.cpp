#include<bits/stdc++.h>
using namespace std;

struct node{
	char value;
	node *l,*r;
	node(char value = '#',node *l = NULL,node *r = NULL):value(value),l(l),r(r){}
}; 

void preorder(node *root){
	if(root != NULL){
		cout<<root->value<<" ";
		preorder(root->l);
		preorder(root->r);
	}
}

void inorder(node *root){
	if(root != NULL){
		inorder(root->l);
		cout<<root->value<<" ";
		inorder(root->r);
	}
}

void postorder(node *root){
	if(root != NULL){
		postorder(root->l);
		postorder(root->r);
		cout<<root->value<<" ";
	}
}

void remove_tree(node *root){
	if(root == NULL)	return;
	remove_tree(root->l);
	remove_tree(root->r);
	delete root;
}

int main(){
	node *A,*B,*C,*D,*E,*F,*G,*H,*I;
	A = new node('A');	B = new node('B');	C = new node('C');
	D = new node('D');	E = new node('E');	F = new node('F');
	G = new node('G');	H = new node('H');	I = new node('I');
	E->l = B;	E->r =G;	B->l = A;	B->r = D;
	G->l = F;	G->r =I;	D->l = C;	I->l = H;
	cout<<"in order:";	inorder(E);	cout<<endl;
	cout<<"pre order:";	preorder(E);	cout<<endl;
	cout<<"post order:";	postorder(E);	cout<<endl;
	remove_tree(E);
	return 0;
} 
