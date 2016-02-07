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

pair<int, pair<int,int> > arr[1003];
int bytes[5], msgs[5];

int main()
{
	int n,m,tst=0;
	while(scanf("%d %d",&n,&m) && (n || m)){
		for(int i=0;i<n;++i)scanf("%d",bytes+i),msgs[i]=i;


		for(int i=0;i<m;++i){
			scanf("%d %d %d",&arr[i].f,&arr[i].s.f,&arr[i].s.s);
		}

		int ans=INT_MAX;
		do{
			priority_queue< pair<int,int> > coming[5], buffer[5];

			for(int i=0;i<m;++i)
				coming[arr[i].f-1].push(mp(-arr[i].s.f,-arr[i].s.s));

			int sz=0,cur=0,ind=0;
			for(int i=0;i<m;++i){
				int msg=arr[i].f-1, l=arr[i].s.f, r=arr[i].s.s;

				if(l==-coming[msg].top().f && msg==msgs[ind]){
					if(r==bytes[msg])++ind;
					coming[msg].pop();

					int x=msgs[ind];
					while(!buffer[x].empty() && !coming[x].empty()){
						if(buffer[x].top().f!=coming[x].top().f)break;

						sz=max(sz,cur);
						cur-=((-buffer[x].top().s)-(-buffer[x].top().f)+1);

						if(-buffer[x].top().s==bytes[x]){
							buffer[x].pop();coming[x].pop();
							++ind;
							if(ind<n)x=msgs[ind];
						}
						else buffer[x].pop(),coming[x].pop();
					}
				}
				else{
					cur+=(r-l+1);
					sz=max(sz,cur);
					buffer[msg].push(mp(-l,-r));
				}
			}
			ans=min(ans,sz);
		}
		while(next_permutation(msgs,msgs+n));

		printf("Case %d: %d\n\n",++tst,ans);
	}
	return 0;
}
