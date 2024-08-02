#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int>PII;
const int N = 100010;
int n;
vector<PII> segs;

void merge(vector<PII> &segs)
{
	vector<PII> res;
	int st = -2e9,ed = -2e9;
	sort(segs.begin(),segs.end());
	for(auto seg:segs)//���� segs does not name a type 
	{
		if(ed < seg.first)
		{
			if(st != -2e9) res.push_back({st,ed});
			st = seg.first;
			ed = seg.second;
		}
		else ed = max(ed,seg.second);
	}
	if(st!=-2e9) res.push_back({st,ed});
	segs = res;
}

int main(){
	cin>>n;
	while(n--)
	{
		int l,r;
		cin>>l>>r;
		segs.push_back({l,r});
		
		merge(segs);
		cout<<segs.size()<<endl;
		return 0;
	}
}
