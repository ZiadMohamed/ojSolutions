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

int arr[25], common[11][25], ans[25], tmp[25], sz[15];
bool have[25];
int k,m;

void comp(int &best){
	int sum=0;
	for(int i=0;i<k;++i)sum+=arr[tmp[i]];

	for(int i=0;i<m;++i){
		bool ok=0;
		for(int j=0;j<sz[i];++j)
			if(have[common[i][j]-1]){ok=1;break;}

		if(ok)sum+=common[i][sz[i]];
	}

	if(sum>best){
		best=sum;
		for(int i=0;i<k;++i)ans[i]=tmp[i];
	}
	else if(sum==best){
		for(int i=0;i<k;++i){
			if(ans[i]<tmp[i])return;
			else if(tmp[i]<ans[i])break;
		}

		for(int i=0;i<k;++i)ans[i]=tmp[i];
	}
}

int main()
{
	int n,tst=0;
	while(scanf("%d %d",&n,&k) && (n || k)){

		for(int i=0;i<n;++i)
			scanf("%d",arr+i);

		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%d",sz+i);
			for(int j=0;j<=sz[i];++j)scanf("%d",&common[i][j]);

			for(int j=0;j<sz[i];++j)arr[common[i][j]-1]-=common[i][sz[i]];
		}

		int best=-1;
		for(int mask=0;mask<(1<<n);++mask){
			if(__builtin_popcount(mask)!=k)continue;

			mem(have,0);
			for(int i=0,j=0;i<n;++i){
				if(mask & (1<<i))tmp[j++]=i,have[i]=1;
			}

			comp(best);
		}


		printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended:",++tst,best);
		for(int i=0;i<k;++i)printf(" %d",1+ans[i]);
		printf("\n\n");
	}
	return 0;
}
