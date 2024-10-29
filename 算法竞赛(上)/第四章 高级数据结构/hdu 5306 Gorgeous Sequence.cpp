//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long
const int N = 1e6+10;

ll sum[N<<2],ma[N<<2],se[N<<2],num[N<<2];
ll ls(ll p){
	return p<<1;
} 

ll  rs(ll p){
	return p<<1|1;
}

void pushup(int p){
	sum[p] = sum[ls(p)] + sum[rs(p)];
	ma[p] = max(ma[ls(p)] , ma[rs(p)]);
	if(ma[ls(p)] == ma[rs(p)]){
		se[p] = max(se[ls(p)],se[rs(p)]);
		num[p] = num[ls(p)] + num[rs(p)];
	}else{
		se[p] = max(se[ls(p)], se[rs(p)]);
		se[p] = max(se[p],min(ma[ls(p)],ma[rs(p)]));
		num[p] = ma[ls(p)] > ma[rs(p)] ? num[ls(p)]:num[rs(p)];
	}
}

void build(int p,int pl,int pr){
	if(pl == pr){
		scanf("%lld",&sum[p]);
		ma[p] = sum[p];	se[p] = -1;	num[p] = 1;
		return;
	}
	ll mid = (pl + pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	pushup(p);
}

void addtag(int p,int x){
	if(x>=ma[p])	return;
	sum[p] -= num[p] * (ma[p] - x);
	ma[p] = x;
}

void pushdown(int p){
	addtag(ls(p),ma[p]);
	addtag(rs(p),ma[p]);
}

void update(int L,int R,int p,int pl,int pr,int x){
	if(x >= ma[p])	return;
	if(L <= pl && pr <= R && se[p] < x){
		addtag(p,x);
		return ;
	}
	pushdown(p);
	ll mid = (pl + pr) >> 1;
	if(L <= mid)	update(L,R,ls(p),pl,mid,x);
	if(R > mid)	update(L,R,rs(p),mid+1,pr,x);
	pushup(p);
}

int queryMax(int L,int R,int p,int pl,int pr){
	if(pl >= L && R >= pr)	return ma[p];
	pushdown(p);
	int res = 0;
	ll mid = (pl + pr) >> 1;
	if(L <= mid)	res = queryMax(L,R,ls(p),pl,mid);
	if(R > mid)	res = max(res,queryMax(L,R,rs(p),mid+1,pr));
	return res;
}

ll querySum(int L,int R,int p,int pl,int pr){
	if(L <= pl && R >= pr)	return sum[p];
	pushdown(p);
	ll res = 0;
	ll mid = (pl + pr)>>1;
	if(L <= mid)	res += querySum(L,R,ls(p),pl,mid);
	if(R > mid)		res += querySum(L,R,rs(p),mid+1,pr);
	return res;
}

int main(){
	int T;	scanf("%d",&T);
	while(T--){
		int n,m;	scanf("%d%d",&n,&m);
		build(1,1,n);
		while(m--){
			int q,L,R,x;	scanf("%d%d%d",&q,&L,&R);
			if(q == 0){
				scanf("%d",&x);
				update(L,R,1,1,n,x);
			}
			if(q == 1)
				printf("%d\n",queryMax(L,R,1,1,n));
			if(q == 2)
				printf("%lld\n",querySum(L,R,1,1,n));
		}
	}
	return 0;
}
