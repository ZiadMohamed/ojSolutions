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

int memo[1005];
vector< vector<int> > v;

int solve(int node){
	if(v[node].empty())return 1;

	int &ret=memo[node];
	if(ret!=-1)return ret;

	int mx=-1,cnt=1;
	for(int i=0;i<v[node].size();i++){
		int x=solve(v[node][i]);
		if(x>mx)mx=x,cnt=1;
		else if(x==mx)cnt++;
	}
	return ret=mx+(cnt>1);
}

int main()
{
	int t;scanf("%d",&t);
	while(t--){
		int cs,m,p;scanf("%d %d %d",&cs,&m,&p);
		mem(memo,-1);
		v.clear();v.resize(m+1);

		while(p--){
			int a,b;scanf("%d %d",&a,&b);
			v[b].pb(a);
		}

		printf("%d %d\n",cs,solve(m));

	}
	return 0;
}
