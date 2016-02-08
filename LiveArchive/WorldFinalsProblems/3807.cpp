#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pi acos(-1.0)
#define EPS 1e-9
#define mem(n,x) memset(n,x,sizeof(n))
typedef long long ll;

using namespace std;

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

int hole[5][5];
bool wall[5][5][5][5];
int n;

bool valid(int x,int y){
	if(x<0 || y<0 || x>=n || y>=n)return 0;
	return 1;
}

bool check(vector< vector<int> > &cur){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(!hole[i][j])continue;
			if(hole[i][j]!=cur[i][j])return 0;
		}
	}
	return 1;
}

int BFS(vector< vector<int> > &v){
	set< vector< vector<int> > > vis;
	queue< vector< vector<int> > > q;
	q.push(v);
	vis.insert(v);

	int moves=0;
	while(!q.empty()){
		int sz=q.size();

		while(sz--){
			vector< vector<int> > cur=q.front();
			q.pop();

			if(check(cur))return moves;

			for(int d=0;d<4;++d){
				vector< vector<int> > nxt=cur;
				int ii=0,inc=1;
				if(!d || d==3)ii=n-1,inc=-1;
				bool ok=1;

				for(;ii>=0 && ii<n && ok;ii+=inc){
					for(int jj=0;jj<n;++jj){
						int i=ii,j=jj;
						if(d>=2)swap(i,j);

						if(!nxt[i][j] || (hole[i][j] && nxt[i][j]>0))continue;
						int x=i, y=j;
						while(true){
							int nx=x+dx[d], ny=y+dy[d];
							if(!valid(nx,ny) || wall[x][y][nx][ny] || (nxt[nx][ny]>0 && !hole[nx][ny]) || (nxt[nx][ny]<0 && hole[nx][ny]))break;
							x=nx,y=ny;
							if(hole[x][y] && !nxt[x][y])break;
						}
						if(x==i && y==j)continue;

						if(hole[x][y]){
							if(nxt[x][y]){
								if(nxt[i][j]<0){nxt[x][y]=nxt[i][j];nxt[i][j]=hole[i][j];}
								else {nxt[x][y]=-nxt[i][j]; nxt[i][j]=0;}
							}
							else{
								if(abs(nxt[i][j])!=hole[x][y]){ok=0;break;}
								else{
									if(nxt[i][j]<0){
										nxt[x][y]=-nxt[i][j];
										nxt[i][j]=hole[i][j];
									}
									else swap(nxt[i][j],nxt[x][y]);
								}
							}
						}
						else{
							if(nxt[i][j]<0){
								nxt[x][y]=-nxt[i][j];
								nxt[i][j]=hole[i][j];
							}
							else swap(nxt[i][j],nxt[x][y]);
						}
					}
				}
				if(ok && !vis.count(nxt))q.push(nxt),vis.insert(nxt);
			}
		}

		++moves;
	}

	return -1;
}

int main()
{
	int m,w,tst=0;
	while(scanf("%d %d %d",&n,&m,&w) && (n || m || w)){
		vector< vector<int> > v(n, vector<int>(n,0));
		int x,y,xx,yy;
		for(int i=0;i<m;++i){
			scanf("%d %d",&x,&y);
			v[x][y]=i+1;
		}

		mem(hole,0);
		for(int i=0;i<m;++i){
			scanf("%d %d",&x,&y);
			hole[x][y]=i+1;
		}

		mem(wall,0);
		for(int i=0;i<w;++i){
			scanf("%d %d %d %d",&x,&y,&xx,&yy);
			wall[x][y][xx][yy] = wall[xx][yy][x][y] = 1;
		}

		int ans=BFS(v);
		printf("Case %d: ",++tst);
		if(ans==-1)printf("impossible\n\n");
		else printf("%d moves\n\n",ans);
	}
	
	return 0;
}
