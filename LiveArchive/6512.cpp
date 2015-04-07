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

int main()
{
	int t;cin>>t;
	while(t--){
		int n,ans=0;double d,a,b,c;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a>>b>>c;
			if(((d/a)*c)<=b)++ans;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
