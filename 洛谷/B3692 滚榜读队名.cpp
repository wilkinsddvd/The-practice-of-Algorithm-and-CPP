#include<bits/stdc++.h>
using namespace std;

struct dui{
	int fa;
	string name;
	int id;
	int guo;
	int to[40];
	int bu[40];
	bool operator<(const dui &l) const {
		if(guo!=l.guo)
			return guo>l.guo;
		else if(fa!=l.fa)
			return fa<l.fa;
		else
			return id<l.id;
	}
}s[1005];

int o;

map<string,int>q;
priority_queue<dui>pai;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		string a,b,c,d;
		cin>>a>>b>>c;
		getline(cin,d);
		int x=0,yy=0,zz=0;
		int p=0;
		for(;p<a.size();p++){
			if(a[p]==':')
				break;
			x = x*10+(a[p]-'0');
		}
		p++;
		
		for(;p<a.size();p++){
			if(a[p] == ':')
				break;
			yy = yy*10 +(a[p]-'0');
		}	
		p++;
		
		for(;p<a.size();p++){
			if(a[p]==':')
				break;
			zz = zz * 10 + (a[p]-'0');
		}
		if(!q[c]){
			q[c] = ++o;
			s[o].name = c;
			s[o].id = o;
			s[o].guo = 0;
			s[o].fa = 0;
			memset(s[o].to,0,sizeof(s[o].to));
			memset(s[o].bu,0,sizeof(s[o].bu));
		}
		int iid = q[c];
		int ti = b[0] - 'A' + 1;
		int shi=x*60 +yy;
		if(s[iid].to[ti])
			continue;
		if(d=="Accepted"){
			s[iid].to[ti] = 1;
			if(shi>240 ||(shi==240 && zz)){
				s[iid].to[ti]=2+shi+20*s[iid].bu[ti];
			}else{
				s[iid].fa += shi + 20 * s[iid].bu[ti];
				s[iid].guo++;
			}
		}else
			s[iid].bu[ti]++;
	}
	for(int i=1;i<=o;i++){
		pai.push(s[i]);
	}
	while(pai.size()>1){
		dui x = pai.top();
		pai.pop();
		cout<<x.name<<endl;
		dui y=pai.top();
		pai.pop();
		for(int i=1;i<=n;i++){
			if(x.to[i]>1){
				x.fa += x.to[i]-2;
				x.guo++;
				x.to[i]=1;
				if(x<y){
					pai.push(x);
					break;
				}
			}
		} 
		pai.push(y);
	}
	cout<<pai.top().name; 
}
