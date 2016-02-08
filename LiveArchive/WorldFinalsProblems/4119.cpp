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
ll D;

ll power(ll x,ll y){
	ll ret=1;
	while(y){
		if(y&1LL)ret=(ret*x)%D;
		x=(x*x)%D;
		y>>=1LL;
	}
	return ret%D;
}

char str[100005];
pair<int,int> arr[103];

int main()
{
	int tst=0;
	while(scanf("%s",str) && str[0]!='.'){
		int n=strlen(str), i=1, sz=0, x=0, extra=0;
		bool sign=1;
		while(str[i]!=')'){

			if(str[i]=='n'){
				if(!x)x=1;
				arr[sz].f=sign?x:-x;
				++i;x=0;
				if(str[i]=='^'){
					++i;
					while(isdigit(str[i]))x=(x*10)+(str[i++]-'0');
					arr[sz].s=x;
					x=0;
				}
				else arr[sz].s=1;
				++sz;
				continue;
			}
			if(str[i]=='+' || str[i]=='-')sign=!(str[i]=='-');
			else x=(x*10)+(str[i]-'0');
			++i;
		}
		if(x!=0)extra=sign?x:-x;

		i+=2;x=0;
		while(i<n)x=(x*10)+(str[i++]-'0');
		D=x?x:1;

		bool check=1;
		for(i=0;i<=arr[0].s+1 && check;++i){
			ll sum=0;
			for(int j=0;j<sz;++j){
				sum=(((sum + (((ll)arr[j].f*power(i,arr[j].s)))%D)%D)+D)%D;
			}
			sum=(((sum+extra)%D)+D)%D;
			if(sum)check=0;
		}
		printf("Case %d: ",++tst);
		puts(check?"Always an integer":"Not always an integer");
	}
	return 0;
}
