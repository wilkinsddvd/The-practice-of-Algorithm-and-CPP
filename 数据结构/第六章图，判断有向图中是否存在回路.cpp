#include<iostream>
#include<string.h>
using namespace std;

const int MAXSIZE = 100;

template<class DataType,class WeightType>

class MGraph{
public:
	MGraph(DataType a[],int n,int e);
	~MGraph(){}
	int TopSort();
	int findVertex(DataType ver);
	int getVertexNum(){return vertexNum;};
	void show();
private:
	int vertexNum;
	int edgeNum;
	DataType vertex[MAXSIZE];
	WeightType edge[MAXSIZE][MAXSIZE];
};

template<class DataType,class WeightType>
MGraph<DataType,WeightType>::MGraph(DataType a[],int n,int e)
{
	vertexNum = n;
	edgeNum = e;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			edge[i][j] = 0;
	for(int i = 0;i<n;++i)
		vertex[i] = a[i];
	for(int k= 0;k<e;++k){
		DataType startVer,endVer;
		cin>>startVer>>endVer;
		int i= findVertex(startVer);
		int j= findVertex(endVer);
		edge[i][j] = 1;
	}
 } 
 
 template<class DataType,class WeightType>
 int MGraph<DataType,WeightType>::findVertex(DataType ver)
 {
 	for(int i=0;i<vertexNum;++i)
 		if(vertex[i] == ver) return i;
 	return -1;
 }
 
 template <class DataType,class WeightType>
 int MGraph<DataType,WeightType>::TopSort()
 {
 	int cont = 0;
 	
 	
 	return cont;
 }
 
 template<class DataType,class WeightType>
 void MGraph<DataType,WeightType>::show()
 {
 	for(int i =0;i<vertexNum;++i){
 		for(int j=0;j<vertexNum;++j)
 			cout<<edge[i][j]<<" ";
 		cout<<endl;
	 }
} 
  
int main(){
	int n,e;
	cin>>n>>e;
	char a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	MGraph<char,int> MG(a,n,e);
	if(MG.getVertexNum() == MG.TopSort())
		cout<<"NO"<<endl;
	else 
		cout<<"YES"<<endl;
	return 0;
}
