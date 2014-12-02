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

int cost[27], dist[1001][1001];

char arr[1001][1001];

int n,m;

bool valid(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m)return 0;
	return 1;
}

int Djikstra(int X,int Y){
	mem(dist,-1);
	dist[X][Y]=0;

	priority_queue< pair<int, pair<int,int> > > q;
	q.push(mp(0,mp(X,Y)));

	while(!q.empty()){
		int c=-q.top().f,x=q.top().s.f,y=q.top().s.s;
		q.pop();

		if(!valid(x,y))return c;

		for(int i=0;i<4;++i){
			int a=x+dx[i],b=y+dy[i];

			if(!valid(a,b)){
				q.push(mp(-c,mp(a,b)));
				continue;
			}

			int tmp=c+cost[arr[a][b]-'A'];
			if(dist[a][b]==-1 || dist[a][b]>tmp){
				dist[a][b]=tmp;
				q.push(mp(-tmp,mp(a,b)));
			}
		}
	}
	return -1;
}

int main()
{
	int t;cin>>t;
	while(t--){
		int k;cin>>k>>m>>n;
		while(k--){
			char c;int x;
			cin>>c>>x;
			cost[c-'A']=x;
		}

		int x,y;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>arr[i][j];
				if(arr[i][j]=='E')x=i,y=j;
			}
		}

		cout<<Djikstra(x,y)<<"\n";
	}
	return 0;
}
