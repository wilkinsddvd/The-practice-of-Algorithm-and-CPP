#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf=1e18;

vector<ll>a,posa;

pair<int,ll> nowA={0,inf};

void apply(vector<ll>&a,pair<int,ll>p){
	int indx=posa[p.first];
	if(a[indx]<nowA.second){
		nowA={indx,a[indx]};
	}
	a[nowA.first]-=p.second;
	nowA.second=a[nowA.first];
} 

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		a.clear();
		posa.clear();
		a.resize(n);
		nowA={0,inf};
		ll mintmp=inf,lastIdx=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]<mintmp){
				mintmp=a[i];
				posa.emplace_back(i);
				lastIdx=i;
			}else{
				posa.emplace_back(lastIdx);
			}
		}
		vector<ll>b(n,0);
		for(int i=0;i<m;i++){
			ll r,w; cin>>r>>w;
			b[r-1]+=w;
		}
		for(int i=0;i<n;i++)
			if(b[i]>0)
				apply(a,{i,b[i]});
		sort(a.begin(),a.end());
		ll ans=0;
		for(int i=0;i<n;i++){
			ans+=a[i];
			cout<<ans<<"\n"[i==n-1]; 
		}
	}
	return 0;
}
