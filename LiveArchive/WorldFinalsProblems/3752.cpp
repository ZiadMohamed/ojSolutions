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

char str[1003];

int main()
{
	int tst=0;
	while(scanf("%s",str) && str[0]!='e'){
		int n=strlen(str);

		multiset<char> st;
		multiset<char>::iterator it;
		for(int i=0;i<n;++i){
			st.insert(str[i]);

			it=st.lower_bound(str[i]);
			++it;

			if(it!=st.end())
				st.erase(it);
		}

		printf("Case %d: %d\n",++tst,int(st.size()));
	}
	return 0;
}
