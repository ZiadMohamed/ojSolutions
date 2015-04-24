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

bool arr[109][109],str[15][15],ans[109][109];


int main()
{
	int t,cs=0;cin>>t;
	while(t--){
		mem(ans,0);
		int n,m;cin>>n>>m;
		for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>arr[i][j];
		int q,r;cin>>q>>r;
		for(int i=0;i<q;++i)for(int j=0;j<r;++j)cin>>str[i][j];

		vector< pair<int,int> > v;
		for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(arr[i][j])v.pb(mp(i,j));

		int a=q/2;
		for(auto X:v){
			int x=X.f,y=X.s;
			if(x-a<0 || x+a>=n || y-a<0 || y+a>=m)continue;
			for(int i=x-a,xx=0;i<=x+a;++i,++xx){
				for(int j=y-a,yy=0;j<=y+a;++j,++yy){
					if(arr[i][j] || str[xx][yy])ans[i][j]=1;
				}
			}
		}

		cout<<"Case "<<++cs<<":\n";
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cout<<ans[i][j];
				if(j!=m-1)cout<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}
