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

pair<int,int> arr[10];
int n, ind[10];

bool ok(double x){
	sort(ind,ind+n);

	do{
		double nxt=arr[ind[0]].f;
		bool check=1;
		for(int i=1;i<n;++i){
			nxt+=x;
			if(nxt-EPS>arr[ind[i]].s){check=0;break;}
			if(nxt+EPS<arr[ind[i]].f)nxt=arr[ind[i]].f;
		}
		if(check)return 1;
	}
	while(next_permutation(ind,ind+n));

	return 0;
}

int main()
{
	int tst=0;
	while(scanf("%d",&n) && n){
		for(int i=0;i<n;++i){
			scanf("%d %d",&arr[i].f,&arr[i].s);
			arr[i].f*=60;arr[i].s*=60;
			ind[i]=i;
		}


		double ans=0.0, sz=1440*60;
		for(sz/=2;sz>EPS;sz/=2){
			if(ok(ans+sz))
				ans+=sz;
		}
		ans=round(ans);

		printf("Case %d: %d:%02d\n",++tst,int(ans)/60,int(ans)%60);
	}
	return 0;
}
