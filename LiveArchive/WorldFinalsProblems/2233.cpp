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

struct hole{
	int x,y,z,r;
	hole(){
		x=y=z=r=0;
	}
}arr[105];



double outerDist(hole a,hole b){
	double x=a.x-b.x, y=a.y-b.y, z=a.z-b.z;
	return sqrt(x*x+y*y+z*z)-a.r-b.r;
}


double dp[105][105];

int main()
{
	int n,cs=0;
	while(scanf("%d",&n) && n!=-1){
		n+=2;
		for(int i=0;i<n;++i){
			scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);
			if(i<n-2)scanf("%d",&arr[i].r);
			else arr[i].r=0;
		}

		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(i==j || outerDist(arr[i],arr[j])+EPS<=0)
					dp[i][j]=0.0;
				else
					dp[i][j]=10.0*outerDist(arr[i],arr[j]);
			}
		}

		for(int k=0;k<n;++k)for(int i=0;i<n;++i)for(int j=0;j<n;++j){
			if(dp[i][j]-EPS>dp[i][k]+dp[k][j])
				dp[i][j]=dp[i][k]+dp[k][j];
		}


		printf("Cheese %d: Travel time = %.0lf sec\n",++cs,dp[n-2][n-1]);
	}

	return 0;
}
