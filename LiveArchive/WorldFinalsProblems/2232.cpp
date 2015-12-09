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

int passengers[30][30];
int arrival[30],depart[30];

pair<int,int> ans[25];

int main()
{
	int n;
	while(scanf("%d",&n) && n){
		mem(passengers,0);

		for(int i=0;i<n;++i){
			int origin,dest,num;
			scanf("%d",&origin);

			int k;scanf("%d",&k);
			while(k--){
				scanf("%d %d",&dest,&num);
				passengers[origin][dest]=num;
			}
		}


		int conf,sz=0;
		while(scanf("%d",&conf) && conf){
			for(int i=0;i<n;++i)
				scanf("%d",arrival+i);

			for(int i=0;i<n;++i)
				scanf("%d",depart+i);

			int traffic=0;
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					traffic+=(1+abs(i-j))*passengers[arrival[i]][depart[j]];
				}
			}
			ans[sz++]=mp(traffic,conf);
		}

		sort(ans,ans+sz);

		puts("Configuration Load");
		for(int i=0;i<sz;++i)
			printf("%5d         %d\n",ans[i].s,ans[i].f);


	}
	return 0;
}
