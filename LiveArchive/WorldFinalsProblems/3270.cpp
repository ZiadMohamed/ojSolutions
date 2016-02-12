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
using namespace std;

typedef long long ll;
typedef complex<double> point;
#define X real()
#define Y imag()
#define vec(a,b) ((b) - (a))
#define dot(a,b) ((conj(a) * (b)).X)
#define cross(a,b) ((conj(a) * (b)).Y)
#define length(v) ((double)hypot((v).Y, (v).X))


point pointSegmentDist(const point &a, const point &b,const point &p){
	double l=((b.Y-a.Y)*(b.Y-a.Y)) + ((b.X-a.X)*(b.X-a.X));
	double t=dot(vec(a,b), vec(a,p)) / l;
	if(t+EPS<0.0)return a;
	else if(t-EPS>1.0)return b;

	return a+t*vec(a,b);
}

point strt;
bool comp(point a, point b){
	return length(vec(strt,a))+EPS<length(vec(strt,b));
}

point bts[51], city[51];
vector< pair<int,int> > adj[51];
int dist[51], visDist[51], ID;


int dijkstra(int st,int en){
	++ID;

	priority_queue< pair<int,int> > q;
	q.push(mp(0,st));

	dist[st]=0;

	while(!q.empty()){
		int cost=-q.top().f, node=q.top().s;
		q.pop();

		if(node==en)return cost;

		for(pair<int,int> x:adj[node]){
			if(visDist[x.f]!=ID || cost+x.s<dist[x.f]){
				visDist[x.f]=ID;
				dist[x.f]=cost+x.s;
				q.push(mp(-cost-x.s,x.f));
			}
		}
	}
	return -1;
}

int main()
{
	int b,n,m,q,tst=0;
	double px,py;
	while(scanf("%d %d %d %d",&b,&n,&m,&q) && (b || n || m || q)){

		for(int i=0;i<b;++i)
			scanf("%lf %lf",&px,&py),bts[i]=point(px,py);

		for(int i=0;i<n;++i){
			scanf("%lf %lf",&px,&py);
			city[i]=point(px,py);
			adj[i].clear();
		}

		int x,y;
		for(int i=0;i<m;++i){
			scanf("%d %d",&x,&y);
			--x;--y;

			vector<point> v{city[x],city[y]};
			for(int j=0;j<b;++j)
				v.pb(pointSegmentDist(city[x],city[y],bts[j]));

			strt=city[x];sort(all(v),comp);


			int switches=0,cur=-1;

			for(point p:v){
				double mn=0,ind=-1;
				for(int j=0;j<b;++j){
					double d=length(vec(p,bts[j]));
					if(ind==-1 || d+EPS<mn)
						mn=d, ind=j;
				}
				if(cur!=-1 && cur!=ind)++switches;
				cur=ind;
			}

			adj[x].pb(mp(y,switches));
			adj[y].pb(mp(x,switches));
		}

		printf("Case %d:\n",++tst);
		while(q--){
			scanf("%d %d",&x,&y);
			int ans=dijkstra(x-1,y-1);
			if(ans==-1)printf("Impossible\n");
			else printf("%d\n",ans);
		}
	}
	return 0;
}
