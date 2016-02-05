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

const int INF=1000000000;

int dp[51][51];
map<string,int> node;

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,tst=0;
	string a,b;
	while(cin>>n>>m && (n || m)){
		node.clear();
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				dp[i][j]=(i==j)?0:INF;

		int cur=0;
		for(int i=0;i<m;++i){
			cin>>a>>b;
			int x,y;
			if(!node.count(a))x=cur,node[a]=cur++;
			else x=node[a];

			if(!node.count(b))y=cur,node[b]=cur++;
			else y=node[b];

			dp[x][y]=dp[y][x]=1;
		}

		for(int k=0;k<n;++k)
			for(int i=0;i<n;++i)
				for(int j=0;j<n;++j)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);

		int ans=0;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				ans=max(ans,dp[i][j]);

		cout<<"Network "<<++tst<<": ";
		if(ans==INF)cout<<"DISCONNECTED\n\n";
		else cout<<ans<<"\n\n";
	}
	return 0;
}
