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

int arr[10];

bool vis[10];


bool exist(int x,int mask){
	while(x){
		int digit=x%10;
		if(!(mask & (1<<digit)) || (vis[digit]))return 0;
		vis[digit]=1;
		x/=10;
	}
	return 1;
}

bool ok(int x,int mask){
	if(exist(x,mask))return 1;

	for(int i=1;i<=x/2;++i){
		mem(vis,0);
		if(i!=x-i && exist(i,mask) && exist(x-i,mask))return 1;
	}
	return 0;
}

int main()
{
	int n,cs=0;
	while(cin>>n && n){
		for(int i=0;i<n;++i)cin>>arr[i];

		int best=INT_MAX;
		for(int mask=0;mask<(1<<10);++mask){
			if(__builtin_popcount(mask)>=__builtin_popcount(best))continue;

			bool check=1;
			for(int i=0;i<n;++i){
				mem(vis,0);
				if(!ok(arr[i],mask)){check=0;break;}
			}

			if(check)best=mask;

		}

		int ans=0;
		for(int i=9;i>=0;--i){
			if(best & (1<<i))ans=(ans*10)+i;
		}
		cout<<"Case "<<++cs<<": "<<ans<<"\n";
	}
	return 0;
}
