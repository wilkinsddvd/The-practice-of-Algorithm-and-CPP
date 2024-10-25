#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;
const int N = 100010;
int n;

vector<PII> segs;
void merge(vector<PII> &segs){
	vector<PII> res;
	// ��ʼ�����ұ߽�
	int st = -2e9,ed = -2e9;
	sort(segs.begin(),segs.end());
	for(auto seg : segs){
		if(ed < seg.first){
			// ������������䣨st,ed�� �Ž�ȥ
			if(st != -2e9)
				res.push_back({st,ed});
			st = seg.first;
			ed = seg.second; 
		}
		// �����ұ߽� 
		else	ed = max(ed,seg.second);
	}
	//��ֹ�����û���κ�����
    //��Ϊ֮ǰ�洢�Ķ���ǰһ�����䣬�������µģ����һ�����������䲢û�б��ϲ���ȥ������Ҫ�ڳ�ѭ�������ж�һ���Ƿ�������һ�����䣬���������䲻Ϊ������ӽ�ȥ
    //������ n��1������if����ȥ��������� n=0��ȥ���Ժ��������
    if(st != -2e9)
		res.push_back({st,ed});
	segs = res; 
} 

int main(){
	cin>>n;
	while(n--){
		int l,r;
		cin>>l>>r;
		segs.push_back({l,r});
		
		merge(segs);
		cout<<segs.size()<<endl;
		return 0;
	}
}
