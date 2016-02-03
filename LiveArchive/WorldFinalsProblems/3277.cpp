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

pair<int,int> w[1000], r[1000];
int vis[1000], visMatch[1000];
int match[1000];
vector<int> adj[1000];
int ID, vmID;

bool comp(pair<int,int> a,pair<int,int> b){
	if(a.f==b.f)return a.s<b.s;
	return a.f>b.f;
}

bool check(int node){
	if(vis[node]==ID)return 0;
	vis[node]=ID;

	for(int x:adj[node]){
		if(visMatch[x]!=vmID || check(match[x])){
			visMatch[x]=vmID;
			match[x]=node;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n,tst=0;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i)
			scanf("%d %d",&w[i].f,&w[i].s);

		sort(w,w+n,comp);


		int m,hrs,minutes;scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%d %d:%d",&r[i].f,&hrs,&minutes);
			minutes+=hrs*60;
			r[i].s=minutes-(14*60);
		}

		for(int i=0;i<n;++i){
			adj[i].clear();
			for(int j=0;j<m;++j)
				if(w[i].f<=r[j].f && w[i].s<=r[j].s)
					adj[i].pb(j);
		}


		++vmID;

		int tents=0,participants=0;
		for(int i=0;i<n;++i){
			++ID;
			if(!check(i))
				++tents,participants+=w[i].f;
		}

		printf("Trial %d: %d %d\n\n",++tst,tents,participants);
	}
	return 0;
}
