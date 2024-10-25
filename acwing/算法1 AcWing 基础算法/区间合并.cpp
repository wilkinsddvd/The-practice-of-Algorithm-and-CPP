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
	// 初始化左右边界
	int st = -2e9,ed = -2e9;
	sort(segs.begin(),segs.end());
	for(auto seg : segs){
		if(ed < seg.first){
			// 不把最初的区间（st,ed） 放进去
			if(st != -2e9)
				res.push_back({st,ed});
			st = seg.first;
			ed = seg.second; 
		}
		// 更新右边界 
		else	ed = max(ed,seg.second);
	}
	//防止输入的没有任何区间
    //因为之前存储的都是前一个区间，所以最新的，最后一个独立的区间并没有被合并进去，所以要在出循环后在判断一次是否添加最后一个区间，如果这个区间不为空则添加进去
    //本题中 n≥1，所以if可以去掉。但如果 n=0，去掉以后会有问题
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
