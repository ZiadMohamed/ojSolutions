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

const int INF=10000000;

int t;
int arr[55], a[55], b[55];
int accum[55];
int n,m1,m2;

int memo[55][203];

int solve(int ind,int tm){

	int &ret=memo[ind][tm];
	if(ret!=-1)return ret;

	ret=INF;
	if(ind<n-1){
		for(int i=0;i<m1;++i){
			int wait=(a[i]+accum[ind])-tm;
			if(wait<0 || tm+wait+arr[ind]>t)continue;
			ret=min(ret,solve(ind+1,tm+wait+arr[ind])+wait);
		}
	}

	if(!ind)
		return ret;

	for(int i=0;i<m2;++i){
		int wait=(b[i]+accum[n-1]-accum[ind])-tm;
		if(wait<0 || tm+wait+arr[ind-1]>t)continue;
		ret=min(ret,solve(ind-1,tm+wait+arr[ind-1])+wait);
	}

	if(ind==n-1)ret=min(ret,t-tm);
	return ret;
}

int main()
{
	int cs=0;
	while(scanf("%d",&n) && n){
		scanf("%d",&t);
	
		for(int i=0;i<n-1;++i){
			scanf("%d",arr+i);
			accum[i+1]=accum[i]+arr[i];
		}

		scanf("%d",&m1);
		for(int i=0;i<m1;++i)
			scanf("%d",a+i);

		scanf("%d",&m2);
		for(int i=0;i<m2;++i)
			scanf("%d",b+i);


		mem(memo,-1);

		int ans=solve(0,0);
		printf("Case Number %d: ",++cs);
		if(ans==INF)printf("impossible\n");
		else printf("%d\n",ans);
	}
	return 0;
}
