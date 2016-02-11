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

int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

int mat1[103][103], mat2[103][103];
int n,m,r1,c1,r2,c2;

struct node{
	int cost, x, y, dir, last;
	node(int _cost,int _x,int _y,int _dir,int _last){
		cost=_cost;x=_x;y=_y;dir=_dir;last=_last;
	}
	bool operator<(node nd)const{
		return cost>nd.cost;
	}
};
unordered_map<int,int> dist[100][100][5];

int dijkstra(){
	for(int i=0;i<100;++i)
		for(int j=0;j<100;++j)
			for(int k=0;k<5;++k)
				dist[i][j][k].clear();

	priority_queue<node> q;
	q.push(node(0,r1,c1,4,0));
	dist[r1][c1][4][0]=0;

	while(!q.empty()){
		node nd=q.top();
		q.pop();

		if(nd.x==r2 && nd.y==c2 && !nd.last)return nd.cost;

		for(int i=0;i<4;++i){
			int nx=nd.x+dx[i], ny=nd.y+dy[i];
			if(nx<0 || nx>=n || ny<0 || ny>=m)continue;

			int edge=(nd.x==nx)?mat1[nx][min(nd.y,ny)]:mat2[min(nd.x,nx)][ny];
			if(!edge)continue;

			int c=edge;
			if(nd.dir!=i)c=(edge*2)+nd.last;
			else if(nx==r2 && ny==c2)c=edge*2;

			int last=(edge==c)?edge:0;

			if(!dist[nx][ny][i].count(last) || nd.cost+c<dist[nx][ny][i][last]){
				dist[nx][ny][i][last]=nd.cost+c;
				q.push(node(nd.cost+c,nx,ny,i,last));
			}


			//try not to stop when you reach the destination
			if(nx==r2 && ny==c2 && nd.dir==i){
				c=edge;
				last=edge;
				if(!dist[nx][ny][i].count(last) || nd.cost+c<dist[nx][ny][i][last]){
					dist[nx][ny][i][last]=nd.cost+c;
					q.push(node(nd.cost+c,nx,ny,i,last));
				}
			}
		}
	}
	return -1;
}

int main()
{
	int tst=0;
	while(scanf("%d %d %d %d %d %d",&n,&m,&r1,&c1,&r2,&c2) && n+m+r1+c1+r2+c2){
		for(int i=0;i<n;++i){
			for(int j=0;j<m-1;++j)scanf("%d",&mat1[i][j]);
			if(i==n-1)break;
			for(int j=0;j<m;++j)scanf("%d",&mat2[i][j]);
		}
		--r1;--c1;--r2;--c2;

		int ans=dijkstra();
		printf("Case %d: ",++tst);
		if(ans==-1)puts("Impossible");
		else printf("%d\n",ans);
	}
	return 0;
}
