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

int main()
{
	int t;scanf("%d",&t);
	while(t--){
		int n,x;scanf("%d",&n);
		set<int> st;
		while(n--){
			scanf("%d",&x);
			st.insert(x);
			set<int>::iterator it=st.upper_bound(x);
			if(it!=st.end())st.erase(it);
		}
		printf("%d\n",int(st.size()));
	}
	return 0;
}
