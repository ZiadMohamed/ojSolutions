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
	int cs=0;
	string a,b;
	while(cin>>a>>b){
		if(a=="END" && b=="END")break;
		sort(all(a));sort(all(b));
		cout<<"Case "<<++cs<<": ";
		if(a==b)cout<<"same\n";
		else cout<<"different\n";
	}
	return 0;
}
