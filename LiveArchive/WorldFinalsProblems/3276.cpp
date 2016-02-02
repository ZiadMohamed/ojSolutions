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

int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};

int n;
pair<int,int> arr[16], wall[16];
int memo[1<<16], vis[1<<16], visID;


bool valid(int x,int y){
	if(x<1 || x>n || y<1 || y>n)return 0;
	return 1;
}



int calc(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}


int solve(int mask){
	if(!mask)return 0;

	if(vis[mask]==visID)return memo[mask];
	vis[mask]=visID;

	memo[mask]=1000000;

	int cnt=__builtin_popcount(mask);

	for(int i=0;i<n;++i)
		if(mask & (1<<i))
			memo[mask]=min(memo[mask],calc(arr[i].f,arr[i].s,wall[cnt-1].f,wall[cnt-1].s)+solve(mask-(1<<i)));


	return memo[mask];
}


void initRowCol(int ind,bool row){
	++visID;

	for(int i=1;i<=n;++i){
		if(row)wall[i-1]=mp(ind,i);
		else wall[i-1]=mp(i,ind);
	}
}

int main()
{
	int tst=0;
	while(scanf("%d",&n) && n){
		int x,y;
		mem(arr,0);
		for(int i=0;i<n;++i){
			scanf("%d %d",&x,&y);
			arr[i]=mp(x,y);
		}


		int ans=INT_MAX;
		for(int i=1;i<=n;++i){
			initRowCol(i,1);
			ans=min(ans,solve((1<<n)-1));

			initRowCol(i,0);
			ans=min(ans,solve((1<<n)-1));
		}

		++visID;
		for(int i=1;i<=n;++i)wall[i-1]=mp(i,i);
		ans=min(ans,solve((1<<n)-1));


		++visID;
		for(int i=1;i<=n;++i)wall[i-1]=mp(i,n-i+1);
		ans=min(ans,solve((1<<n)-1));


		printf("Board %d: %d moves required.\n\n",++tst,ans);
	}
	return 0;
}
