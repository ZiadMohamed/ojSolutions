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

int n;
ll memo[1003][1003][2][2];

ll solve(int ind,int cnt,bool prev,bool st){
	if(ind==n)return (cnt+cnt+4==n && (!prev || (prev && !st)));

	ll &ret=memo[ind][cnt][prev][st];
	if(ret!=-1)return ret;

	ret=0;
	ret+=solve(ind+1,cnt,0,(!ind)?0:st);
	if(!prev)ret+=solve(ind+1,cnt+1,1,(!ind)?1:st);
	return ret;
}

int main()
{
	int tst=0;
	while(scanf("%d",&n) && n){
		mem(memo,-1);
		printf("Case %d: %lld\n",++tst,solve(0,0,0,0));
	}
	return 0;
}
