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
int memo[16][1<<16], vis[16][1<<16], visID;
pair<int,int> arr[16], wall[16];


bool valid(int x,int y){
	if(x<1 || x>n || y<1 || y>n)return 0;
	return 1;
}


int calc(int x1,int y1,int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}

int solve(int ind,int mask){
	if(ind==n)return 0;

	if(vis[ind][mask]==visID)return memo[ind][mask];
	vis[ind][mask]=visID;

	memo[ind][mask]=1000000;

	for(int i=0;i<n;++i){
		if((mask & (1<<i)))continue;
		memo[ind][mask]=min(memo[ind][mask],calc(wall[ind].f,wall[ind].s,arr[i].f,arr[i].s)+solve(ind+1,mask|(1<<i)));
	}

	return memo[ind][mask];
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
		for(int i=0;i<n;++i){
			scanf("%d %d",&x,&y);
			arr[i]=mp(x,y);
		}


		int ans=INT_MAX;
		for(int i=1;i<=n;++i){
			initRowCol(i,1);
			ans=min(ans,solve(0,0));

			initRowCol(i,0);
			ans=min(ans,solve(0,0));
		}

		++visID;
		for(int i=1;i<=n;++i)wall[i-1]=mp(i,i);
		ans=min(ans,solve(0,0));


		++visID;
		for(int i=1;i<=n;++i)wall[i-1]=mp(i,n-i+1);
		ans=min(ans,solve(0,0));


		printf("Board %d: %d moves required.\n\n",++tst,ans);
	}
	return 0;
}
