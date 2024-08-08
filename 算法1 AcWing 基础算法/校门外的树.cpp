#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;
vector<pii> segs;

// 合并区间

void merge(vector<pii> &segs){
	vector<pii> res;
	int st = -1,ed = -1;
	for(auto seg:segs){
		if(ed < seg.first){
			if(~st)
				res.push_back({st,ed});
			st = seg.first,ed = seg.second;
		}
		else	ed = max(ed,seg.second);
	}
	if(~st)
		res.push_back({st,ed});
	segs = res;
} 

int main(){
	int l,m;
	cin>>l>>m;
	while(m--){
		int st,ed;
		cin>>st>>ed;
		segs.push_back({st,ed});
	}
	sort(segs.begin(),segs.end());
	merge(segs);
	
	// 0~L 一共有 L+1 棵树 
	l += 1;
	
	for(auto seg:segs){
		// cout << seg.first << ' ' << seg.second << endl;
		l -=  (seg.second - seg.first + 1); 
	}
	cout << l << endl;
	return 0;
}
