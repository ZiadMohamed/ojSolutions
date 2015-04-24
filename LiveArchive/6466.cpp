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
	int t;cin>>t;
	while(t--){
		int cs;
		double d,a,b,x;
		cin>>cs>>d>>a>>b>>x;
		cout<<cs<<" "<<fixed<<setprecision(2)<<(d/(a+b))*x<<"\n";
	}
	return 0;
}
