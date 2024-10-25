#include<iostream>
#include<unordered_map>
#include<queue>
using namespace std;

int bfs(string start){
	//��ֹ״̬
	string end = "12345678x";
	// ��ϣ��洢����
	unordered_map<string,int> d;
	// ��ʼ������
	d[start] = 0;
	queue<string> q;
	q.push(start);
	
	int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
	
	while(q.size()){
		auto t = q.front();
		q.pop();
		
		int distance = d[t];
		//������ֹ����ͷ��� 
		if(t == end) return distance;
		
		int k = t.find('x');
		int x = k/3,y = k%3;
		
		for(int i=0;i<4;i++){
			int a = x + dx[i],b = y + dy[i];
			if(a>=0 && a<3 && b >= 0 && b<3){
				// ��һ����״̬
				swap(t[k],t[a*3+b]);
				if(!d.count(t)){
					// ���¾���
					d[t] = distance + 1;
					q.push(t); 
				}
				// ����ǰһ��
				swap(t[k],t[a*3+b]); 
			}
		}
	} 
	return -1;
}

int main(){
	string start;
	
	for(int i=0;i<9;i++){
		char c;
		cin>>c;
		start += c;
	}
	
	cout<<bfs(start)<<endl;
	return 0;
}
