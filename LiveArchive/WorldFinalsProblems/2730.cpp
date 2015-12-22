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

vector<int> adj[55];
int dist[55], p;

int charCode(char c){
	return isupper(c)? tolower(c)-'a'+26 : c-'a';
}

bool dijkstra(int st,int have,int en){
	mem(dist,-1);

	priority_queue< pair<int,int> > q;
	q.push(mp(0,st));
	dist[st]=0;

	while(!q.empty()){
		int cost=-q.top().f,node=q.top().s;
		q.pop();

		int cur=have-cost;
		if(node==en)
			return (cur>=p);


		for(int i=0;i<adj[node].size();++i){
			int newCost=1, newNode=adj[node][i];
			if(newNode>25)newCost=(cur+19)/20;

			if(dist[newNode]==-1 || cost+newCost<dist[newNode]){
				dist[newNode]=cost+newCost;
				q.push(mp(-cost-newCost,newNode));
			}
		}
	}
	return 0;
}

int main()
{
	int n,cs=0;
	while(scanf("%d",&n) && n!=-1){
		char c1,c2;
		for(int i=0;i<55;++i)adj[i].clear();

		for(int i=0;i<n;++i){
			scanf(" %c %c",&c1,&c2);
			int x=charCode(c1),y=charCode(c2);
			adj[x].pb(y);
			adj[y].pb(x);
		}
		scanf("%d %c %c",&p,&c1,&c2);
		int st=charCode(c1),en=charCode(c2);

		int low=p,high=4000;
		while(low<=high){
			int mid=(low+high)>>1;
			if(dijkstra(st,mid,en))
				high=mid-1;
			else
				low=mid+1;
		}
		printf("Case %d: %d\n",++cs,low);
	}
	return 0;
}
