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

vector<pair<int,int> > adj[10004];

pair<int, pair<int,int> > edge[250005];

int dist[10004], dist2[10004];

void dijkstra(int src,int dest,bool f){
	priority_queue< pair<int,int> > q;
	q.push(mp(0,src));

	while(!q.empty()){
		int cost=-q.top().f,node=q.top().s;
		q.pop();

		for(int i=0;i<adj[node].size();++i){
			int newNode=adj[node][i].f,newCost=adj[node][i].s;
			if(f && (dist[newNode]==-1 || cost + newCost < dist[newNode])){
				dist[newNode] = cost + newCost;
				q.push(mp(-cost-newCost,newNode));
			}
			else if(!f && (dist2[newNode]==-1 || cost + newCost < dist2[newNode])){
				dist2[newNode] = cost + newCost;
				q.push(mp(-cost-newCost,newNode));
			}
		}
	}
}

int main()
{
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		for(int i=0;i<n;++i)adj[i].clear();

		for(int i=0;i<m;++i){
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			adj[a].pb(mp(b,c));
			adj[b].pb(mp(a,c));
			edge[i]=mp(a,mp(b,c));
		}

		mem(dist,-1);mem(dist2,-1);

		dist[0]=0;dist2[n-1]=0;

		dijkstra(0,n-1,1);
		dijkstra(n-1,0,0);

		int ans=0;

		for(int i=0;i<m;++i){
			int a=edge[i].f,b=edge[i].s.f,c=edge[i].s.s;

			if(dist[a]>dist[b])swap(a,b);

			if(dist[a]+dist2[b]+c==dist[n-1])
				ans+=c;
		}

		printf("%d\n",ans*2);
	}
	return 0;
}
