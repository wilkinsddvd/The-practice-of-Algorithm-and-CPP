#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int>PII;
const int N = 300010;

vector<int>alls;
vector<PII>add,query;

int a[N],s[N];

int find(int x){
	int l = 0,r = alls.size()-1;
	while(l <= r)
	{
		int mid = (l+r) >> 1;
		if(alls[mid] == x) return mid+1;
		else r = mid -1;
	}
	return 0;
}

int main(){
	int n,m;
	cin>>n>>m;
	while(n--)
	{
		int x,c;
		cin>>x>>c;
		add.push_back({x,c});
		alls.push_back(x);
	}
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		query.push_back({l,r}); 
		alls.push_back(l);
		alls.push_back(r);
	}
	sort(alls.begin(),alls.end());
	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	for(auto item : add)// ´ËÐÐ±¨´í  item does not name a type
	{
		int x = find(item.first);
		a[x] += item.second;
	}
	for(int i=1;i <= alls.size();i++) s[i] = s[i-1] + a[i];
	for(auto item : query)
	{
		int l = find(item.first), r = find(item,second);
		cout<<s[r]-s[l-1]<<endl;
	}
	return 0;
}

vector<int>::iterator unique(vector<int> &a)
{
	int j=0;
	for(int i=0;i<a.size();i++)
	{
		if(!i|| a[i] != a[i-1])
			a[j++] = a[i];
	}
	return a.begin()+j;
}
