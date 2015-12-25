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

int dx[]={1,0,0,-1,1,-1,1,-1};
int dy[]={0,1,-1,0,1,-1,-1,1};

bool grid[103][103];
int arr[103][103];
int r,c,n;

int par[10001],rnk[10001];
int vis[10001];

map< pair<int,int> ,int> cost;


void dfs(int x,int y){
	arr[x][y]=n;

	for(int i=0;i<8;++i){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0 && nx<r && ny>=0 && ny<c && arr[nx][ny]==-1 && grid[nx][ny])
			dfs(nx,ny);
	}
}



void bridgeSingleRow(int x){
	int ind=-1,prev=-1;
	for(int i=0;i<c;++i){
		if(arr[x][i]==-1)continue;
		if(prev==-1){ind=i;prev=arr[x][i];continue;}
		if(arr[x][i]==prev)ind=i;
		else{
			int a=min(prev,arr[x][i]),b=max(prev,arr[x][i]);
			if(cost.count(mp(a,b)))
				cost[mp(a,b)]=min(cost[mp(a,b)],i-ind-1);
			else
				cost[mp(a,b)]=i-ind-1;

			prev=arr[x][i];ind=i;
		}
	}
}

void bridgeRows(){
	bridgeSingleRow(0);

	for(int i=0;i<r-1;++i){
		int ind=-1,prev=-1;
		for(int j=0;j<c;++j){
			if(arr[i][j]==-1 && arr[i+1][j]==-1)continue;
			int tmp=arr[i][j];
			if(arr[i][j]==-1)tmp=arr[i+1][j];

			if(prev==-1){ind=j;prev=tmp;continue;}
			if(tmp==prev)ind=j;
			else{
				int a=min(prev,tmp),b=max(prev,tmp);
				if(cost.count(mp(a,b)))
					cost[mp(a,b)]=min(cost[mp(a,b)],j-ind-1);
				else
					cost[mp(a,b)]=j-ind-1;

				prev=tmp;ind=j;
			}
		}
	}

	bridgeSingleRow(r-1);
}


void bridgeSingleCol(int x){
	int ind=-1,prev=-1;
	for(int i=0;i<r;++i){
		if(arr[i][x]==-1)continue;
		if(prev==-1){ind=i;prev=arr[i][x];continue;}
		if(arr[i][x]==prev)ind=i;
		else{
			int a=min(prev,arr[i][x]),b=max(prev,arr[i][x]);
			if(cost.count(mp(a,b)))
				cost[mp(a,b)]=min(cost[mp(a,b)],i-ind-1);
			else
				cost[mp(a,b)]=i-ind-1;

			prev=arr[i][x];ind=i;
		}
	}
}

void bridgeCols(){
	bridgeSingleCol(0);

	for(int j=0;j<c-1;++j){
		int ind=-1,prev=-1;
		for(int i=0;i<r;++i){
			if(arr[i][j]==-1 && arr[i][j+1]==-1)continue;
			int tmp=arr[i][j];
			if(arr[i][j]==-1)tmp=arr[i][j+1];

			if(prev==-1){ind=i;prev=tmp;continue;}
			if(tmp==prev)ind=i;
			else{
				int a=min(prev,tmp),b=max(prev,tmp);
				if(cost.count(mp(a,b)))
					cost[mp(a,b)]=min(cost[mp(a,b)],i-ind-1);
				else
					cost[mp(a,b)]=i-ind-1;

				prev=tmp;ind=i;
			}
		}
	}

	bridgeSingleCol(c-1);
}



int getPar(int x){
	if(x==par[x])return x;
	return par[x]=getPar(par[x]);
}

void link(int x,int y){
	if(rnk[x]>rnk[y])swap(x,y);
	par[x]=y;
	if(rnk[x]==rnk[y])++rnk[y];
}

bool unionSets(int x,int y){
	x=getPar(x),y=getPar(y);
	if(x==y)return 0;

	link(x,y);
	return 1;
}


int main()
{
	int cs=0;
	while(scanf("%d %d",&r,&c)){
		if(r==0 && c==0)break;
		char ch;
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				if(j)scanf("%c",&ch);
				else scanf(" %c",&ch);
				grid[i][j]=(ch=='#');
			}
		}

		mem(arr,-1);
		n=0;
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				if(arr[i][j]==-1 && grid[i][j])
					dfs(i,j),++n;
			}
		}

		if(cs)printf("\n");
		printf("City %d\n",++cs);
		if(n<2){
			printf("No bridges are needed.\n");
			continue;
		}

		cost.clear();

		bridgeRows();
		bridgeCols();

		if(cost.empty()){
			printf("No bridges are possible.\n");
			printf("%d disconnected groups\n",n);
			continue;
		}

		priority_queue<pair<int, pair<int,int> > > q;

		for(auto it=cost.begin();it!=cost.end();++it)
			q.push(mp(-it->s,mp(it->f.f,it->f.s)));


		for(int i=0;i<n;++i)
			par[i]=i,rnk[i]=1;


		int totCost=0,num=0;
		while(!q.empty()){
			int c=-q.top().f,x=q.top().s.f,y=q.top().s.s;
			q.pop();

			if(unionSets(x,y))
				totCost+=c,++num;
		}

		int components=1;
		int p1=getPar(0);
		for(int i=1;i<n;++i){
			int p2=getPar(i);
			if(vis[p2]!=cs && p1!=p2)
				++components,vis[p2]=cs;
		}

		printf("%d ",num);
		if(num==1)printf("bridge");
		else printf("bridges");
		printf(" of total length %d\n",totCost);


		if(components>1)
			printf("%d disconnected groups\n",components);
	}
	return 0;
}
