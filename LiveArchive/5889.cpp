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
	string s;
	getline(cin,s);
	while(t--){
		getline(cin,s);
		int b=0,g=0;
		for(char x:s){
			x=tolower(x);
			if(x=='b')++b;
			else if(x=='g')++g;
		}
		cout<<s<<" is ";
		if(g>b)cout<<"GOOD\n";
		else if(b>g)cout<<"A BADDY\n";
		else cout<<"NEUTRAL\n";
	}
	return 0;
}
