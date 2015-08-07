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

ll pw[31];
int arr[30][30];
int vis[30],cur,n;
unordered_map<ll,double> memo;

int dfs(int node){
	vis[node]=cur;
	int ret=1;
	for(int i=0;i<n;++i)if(arr[node][i]==cur && vis[i]!=cur)ret+=dfs(i);
	return ret;
}

double comp(int n){
	return (n*(n-1))/2.0;
}

double solve(ll hash, vector<int> &v){
	if(v.size()==1)return 0.0;

	if(memo.count(hash))return memo[hash];

	double p=0.0;
	for(int i=0;i<v.size();++i)p+=comp(v[i]);
	p/=comp(n);

	double q=1.0-p;
	double ret1=p/q,ret2=0.0;
	for(int i=0;i<v.size();++i){
		for(int j=i+1;j<v.size();++j){

			vector<int> z{v[i]+v[j]};
			ll nhash=pw[v[i]+v[j]];
			for(int k=0;k<v.size();++k)
				if(k!=i && k!=j)z.pb(v[k]),nhash+=pw[v[k]];

			ret2+=(v[i]*v[j]/comp(n))*(solve(nhash,z)+1);
		}
	}
	ret2/=q;
	return memo[hash]=ret1+ret2;
}

int main()
{
	pw[0]=1;
	for(int i=1;i<=30;++i)pw[i]=pw[i-1]*37;
	int m;
	while(~scanf("%d %d",&n,&m)){
		++cur;
		for(int i=0;i<m;++i){
			int x,y;scanf("%d %d",&x,&y);
			--x;--y;
			arr[x][y]=arr[y][x]=cur;
		}

		ll hash=0;
		vector<int> v;
		for(int i=0;i<n;++i){
			if(vis[i]==cur)continue;
			int sz=dfs(i);
			v.pb(sz);
			hash+=pw[sz];
		}

		printf("%.6f\n",solve(hash,v));
		memo.clear();
	}
	return 0;
}
