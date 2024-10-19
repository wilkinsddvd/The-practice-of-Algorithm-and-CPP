#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

const int dx[4] = {1,-1,-1,1};
const int dy[4] = {1,1,-1,-1};
const char a[5] = "\\/\\/";
const int ix[4] = {0,-1,-1,0};
const int iy[4] = {0,0,-1,-1};

deque<int>x;
deque<int>y;

char map[505][505];
int vis[505][505];

int l,c;
void bfs(){
	memset(vis,0x3f,sizeof(vis));
	x.push_back(0);
	y.push_back(0);
	vis[0][0] = 0;
	while(!x.empty()){
		int xx = x.front();
		int yy = y.front();
		x.pop_front();
		y.pop_front();
		for(int i=0;i<4;i++){
			int dnx = xx+dx[i];
			int dny = yy+dy[i];
			int inx = xx+ix[i];
			int iny = yy+iy[i];
			if(dnx >= 0 && dnx <= l && dny >= 0 && dny <= c){
				if(a[i] != map[inx][iny]){
					int t = vis[xx][yy] + 1;
					if(t<vis[dnx][dny]){
						x.push_back(dnx);
						y.push_back(dny);
						vis[dnx][dny] = t;
					}
				}
				else{
					int t = vis[xx][yy];
					if(t<vis[dnx][dny]){
						x.push_front(dnx);
						y.push_front(dny);
						vis[dnx][dny] = t;
					}
				}
			}
		}
	} 
	cout<<vis[l][c]<<endl;
}

int main(){
	cin>>l>>c;
	for(int i=0;i<l;i++)
		cin>>map[i];
	if((l+c)%2)
		cout<<"NO SOLUTION\n";
	else bfs();
	return 0;
}
