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

vector<ll> v;

bool check(ll x){
	ll val=x;
	while(true){
		if(x==v[v.size()-1])break;
		int ind=lower_bound(all(v),x+val)-v.begin();
		if(ind==v.size())return 0;
		if(v[ind]!=x+val)return 0;
		x+=val;
	}
	return 1;
}

int main()
{
	int t;cin>>t;
	while(t--){
		int cs,n;cin>>cs>>n;v.clear();v.resize(n);
		cin>>v[0];
		for(int i=1;i<n;++i)cin>>v[i],v[i]+=v[i-1];

		ll ans=v[n-1];
		for(int i=0;i<n;++i){
			if(check(v[i])){ans=v[i];break;}
		}
		cout<<cs<<" "<<ans<<"\n";
	}
	return 0;
}
