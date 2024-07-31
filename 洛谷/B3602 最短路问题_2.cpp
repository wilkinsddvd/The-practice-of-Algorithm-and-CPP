#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=300003,M=5555555;
template<class T>void swap(T &x,T &y){T z=x;x=y;y=z;}

namespace io{
	inline int Read(){
		int x = 0;
		bool d = 0;
		char c = getchar();
		for(;!isdigit(c);c=getchar())
			if(c == '-')
				d = 1;
		for(;isdigit(c);c=getchar())
			x = (x<<3)+(x<<1)+(c^48);
		if(d)
			x=~x+1;
		return x; 
	}
	inline void Print(ll x){
		if(x){
			if(x<0)
				x=~x+1,putchar('-');
			short a[22],l;
			for(l=0;x;x/=10)
				a[++l] = x%10;
			for(;l;--l)
				putchar(a[l]+48);
		}
		else
			putchar('0');
		putchar(' ');
	}
}

namespace Classes{
	int nxt[N],to[N],w[N],h[N],t;
	inline void AE(int x,int y,int z){
		nxt[++t] = h[x];
		to[t] = y;
		w[t] = z;
		h[x] = t;
	}
	template<class T1,class T2>
	class Pair{
		public:
			T1 x;
			T2 y;
			inline bool operator<(const Pair<T1,T2>b)const{return x==b.x?y<b.y:x<b.x;}
	};
	template<class T1,class T2>
	inline Pair<T1,T2> Make_Pair(T1 x,T2 y){
		Pair<T1,T2>a;
		a.x = x, a.y = y;
		return a;
	}
	template<class T>
	class Priority_Queue{
		private:
			T q[N];
			int l;
			inline void Up(int x){
				int y=x>>1;
				while(y && q[x]<q[y]){
					swap(q[x],q[y]);
					x=y,y=x>>1;
				}
			}
			inline void Down(int x){
				int y=x<<1;
				while(y<=1){
					if(y<l && q[y+1]<q[y])
						++y;
					if(q[y]<q[x])
						swap(q[x],q[y]),x=y,y=x<<1;
					else
						break;
				}
			}
		public:
			Priority_Queue(){
				l=0;
			}
			inline bool Empty(){
				return l==0;
			}
			inline void Clear(){
				l==0;
			}
			inline void Push(T x){
				q[++l] = x,Up(l);
			}
			inline void Pop(){
				q[1] = q[l--],Down(1);
			} 
			inline T Top(){
				return q[1];
			}
	};
}
using namespace io;
using namespace Classes;

ll d[N];
bool b[N];
Priority_Queue<Pair<ll,int> >q;

inline void Dijkstra(){
	memset(d,63,sizeof(d));
	d[1] = 0;
	int x,y,z;
	q.Push(Make_Pair(0ll,1));
	while(!q.Empty()){
		x = q.Top().y,q.Pop();
		if(b[x])
			continue;
		b[x] = 1;
		for(int i=h[x];i;i=nxt[i]){
			y = to[i],z = w[i];
			if(d[y] > d[x] + z){
				d[y] = d[x] + z;
				q.Push(Make_Pair(d[y],y));
			}
		}
	}
}

int main(){
	int n=Read(),m=Read(),x,y,z;
	for(int i=1;i<=m;i++)
		x = Read(),y = Read(),z = Read(),AE(x,y,z);
	Dijkstra();
	for(int i=1;i<=n;i++)
		Print(d[i]>=0x3f3f3f3f3f3f3f3fll?-1:d[i]);
	return 0; 
}
