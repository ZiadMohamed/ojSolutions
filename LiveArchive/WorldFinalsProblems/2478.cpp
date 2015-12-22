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

pair< pair<int,int> ,int> arr[55];
bool vis[55];

ll dist(ll x1,ll y1,ll x2,ll y2){
	return ((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2));
}

int par[55],rnk[55];

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
	int n,cs=0;
	while(scanf("%d",&n) && n){
		double all=0;
		for(int i=0;i<n;++i){
			scanf("%d %d %d",&arr[i].f.f,&arr[i].f.s,&arr[i].s);
			all+=arr[i].s;
			par[i]=i;
			rnk[i]=1;
		}


		priority_queue< pair<ll, pair<int,int> > > q;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				q.push(mp( -dist(arr[i].f.f,arr[i].f.s,arr[j].f.f,arr[j].f.s) , mp(i,j)));



		mem(vis,0);
		double sum=0;
		while(!q.empty()){
			ll cost=-q.top().f;
			int x=q.top().s.f,y=q.top().s.s;
			q.pop();

			if(!unionSets(x,y))continue;

			double tm=sqrt(cost);

			for(int i=1;i<n;++i){
				if(!vis[i] && getPar(i)==getPar(0)){
					sum+=(arr[i].s*tm);
					vis[i]=1;
				}
			}

		}
		printf("Island Group: %d Average %.2lf\n\n",++cs,sum/all);
	}
	return 0;
}
