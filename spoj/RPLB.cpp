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

int n,k;
int arr[1001],memo[1001][1001];

int solve(int ind,int sum){
	if(sum>k)return -INT_MAX;
	if(ind>=n)return 0;

	int &ret=memo[ind][sum];
	if(ret!=-1)return ret;

	return ret=max(solve(ind+1,sum),solve(ind+2,sum+arr[ind])+arr[ind]);
}

int main()
{
	int t,cs=0;scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;++i)scanf("%d",arr+i);
		mem(memo,-1);
		printf("Scenario #%d: %d\n",++cs,solve(0,0));
	}
	return 0;
}
