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

int arr[101],v[101];

int main()
{
	int t,cs=0;cin>>t;
	while(t--){
		int n,m;cin>>n>>m;
		for(int i=0;i<n;++i)cin>>arr[i];
		sort(arr,arr+n);
		int ans=0;
		for(int i=1;i<n;++i)v[i-1]=arr[i]-arr[i-1],ans+=v[i-1];
		sort(v,v+n-1);
		for(int i=n-2;i>=n-m;--i)ans-=v[i];
		cout<<"Case #"<<++cs<<": "<<ans<<'\n';
	}
	return 0;
}
