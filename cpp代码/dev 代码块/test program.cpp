#include<bits/stdc++.h>
using namespace std;

#define ROWS 10

#define COlS 10

//ֱ�ߴ��� 
#define ZXDJ 10
//б�ߴ��� 
#define XXDJ 14

//����ö��
enum direct{p_up,p_down,p_left,p_right,p_lup,p_ldown,p_rup,p_rdown}; 

struct MyPoint{
	int row,col;
	int f,g,h;
};

//���ĵĽڵ����� 
struct treeNode{
	MyPoint pos;				//��ǰ�ڵ����� 
	vector<treeNode*> childs; //��ź��ӽڵ�ָ��� ����(����) 
	treeNode* pParent; 		//ָ�򸸽ڵ� 
};

//�������ڵ�ĺ���
treeNode* createTreeNode(Mypoint.pos);

//�ж�һ�����ܲ�����
bool canWalk(int map[ROWS][COLS],bool pathMap[ROWS][COLS]),Mypoint pos); 

//����Hֵ
int getH(MyPoint pos,MyPoint endPos);


int main(){
	int map[ROWS][COLS]={
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0,0},	
	};
	
	//���
	int begRow=1;
	int begCol=1;
	MyPoint begPos = {1,1};//begPos.row begPos.col
	//�ص� 
	MyPoint endPos = {6,7};
	
	bool pathMap[ROWS][COLS]={0};//0 false û���߹� 1 �߹�
	
	//�����Ϊ�߹� 
	pathMap[begPos.row[begPos.col] = true;
	
	//���ṹ
	treeNode* pRoot = NULL;
	
	//����Ϊ���ĸ��ڵ� 
	pRoot = createTreeNode(begpos);
	
	//����
	vector<treeNode*> buff; 
	vector<treeNode*>::iterator it;
	vector<treeNode*>::iterator itMin;	
	//��ǰ��
	treeNode* pCurrent = pRoot;
	
	treeNode* pChild = NULL; 
	
	bool isFindEnd = false;
	
	while(1){
		for(itn i=0;i<8;i++){
			pChild = createTreeNode(pCurrent->pos);
			switch(i){
				case p_up:
					 pChild->pos.row--;
					 pChild->pos.g += ZXDJ;
					 break;
				case p_down:
					 pChild->pos.row++;
					 pChild->pos.g += ZXDJ;
					 break;
				case p_left:
					 pChild->pos.col--;
					 pChild->pos.g += ZXDJ;
					 break;				
				case p_right:
					 pChild->pos.col++;
					 pChild->pos.g += ZXDJ;
					 break;
				case p_lup:
					 pChild->pos.row--;
					 pChild->pos.col--;
					 pChild->pos.g += ZXDJ;
					 break;
				case p_ldown:
					 pChild->pos.row++;
					 pChild->pos.cow--;
					 pChild->pos.g += ZXDJ;
					 break;
				case p_rup:
					 pChild->pos.row--;
					 pChild->pos.col++;
					 pChild->pos.g += ZXDJ;
					 break;
				case p_rdown:
					 pChild->pos.row++;
					 pChild->pos.col++;
					 pChild->pos.g += ZXDJ;
					 break;				
			}//end of switch(i) 
			
			if(canwalk(map.pathMap,pChild->pos)){
				 pChild->pos.h = getH(pChild->pos,endPos);
				 pChild->pos.f = pChild->pos.g + pChild->pos.h;
				 pCurrent->childs.push_back(pChild);
				 pCurrent->pParent = pCurrent;
				 
				 buff.push_back(pChild);
			}
			else{//������
				//�ͷ� 
				delete pChild;
			}
		}//end of for(int i=0;i<8;i++)
		itMin = buff.begin();//�����һ����С 
		for(it=buff.begin();it!=buff.end();it++){
			itMin = ((*itMin)->pos.f <(*it)->pos.f)?itMin:it; 
		}
		pCurrent = *itMin;
		buff,erase(itMin);
		if(pCurrent->pos.row == endPos.row && pCurrent->pos.col==endPos.col){
			isFindEnd = true;
			break;
		}
		
		//��ͼ�ұ��˻�û�ҵ��ص�
		if(buff.size()==0) break; 
		
	}//end of while(1)
	if(isFindEnd){
		printf("�ҵ��յ���!\n");
		printf("path:");
		while(pCurrent){
			print("(%d,%d)",pCurrent->pos.row,pCurrent->pos.col);
			pCurrent = pCurrent->pParent; 
		}
		printf("\n");
	}
	return 0;	
	
}

int getH(MyPoint pos,MyPoint endPos){
	int x = (endPos.col > pos.col) ? (endPos.col - pos.col):
		(pos.col - endPos.col);
	int y = (endPos.row > pos.col) ? (endPos.col - pos.col):
		(pos.row - endPos.row);
		
	return (x+y)*ZXDJ; 
}

bool canWalk(int map[ROWS][COLS],bool pathMap[ROWS][COLS]),Mypoint pos){
	//1.�Ƿ��ڵ�ͼ��Χ�� 
	if(pos.row<0||pos.row>=ROWS||
		pos.col<0||pos.col>=COLS) return false;
	//2.�Ƿ��߹� 
	if(pathMap[pos.row][pos.col])	return false;
	//3.�Ƿ��ϰ� 
	if(map[pos.row][pos.col]) return false;
	
	return true; 
}

//�������ڵ�ĺ��� 
treeNode* createTreeNode(Mypoint pos){
	treeNode* pNew = new TreeNode;
	memset(pNew,0,sizeof(treeNode));
	
	pNew->pos= pos ;
	return pNew;
}

