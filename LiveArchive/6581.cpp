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
	while(t--){
		map<string,bool> m;
		getline(cin,s);
		getline(cin,s);
		while(true){
			string a,b,c;
			cin>>a>>b>>c;
			if(a=="what"){
				string tmp1,tmp2;cin>>tmp1>>tmp2;
				stringstream ss(s);
				string z;
				bool f=1;
				while(ss>>z){
					if(m[z])continue;
					if(!f)cout<<" ";
					else f=0;
					cout<<z;
				}
				break;
			}
			m[c]=1;
		}
		cout<<"\n";

	}
	return 0;
}
