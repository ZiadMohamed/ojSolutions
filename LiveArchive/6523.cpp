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
	map<string,string> m;
	int n;cin>>n;string s;getline(cin,s);
	while(n--){
		getline(cin,s);
		stringstream ss(s);string z,tmp;ss>>z;
		while(ss>>tmp){
			for(int i=0;i<tmp.size();i++)tmp[i]=tolower(tmp[i]);
			m[tmp]=z;
		}
	}
	s.clear();
	while(getline(cin,s)){
		for(int i=0;i<s.size();i++){
			s[i]=tolower(s[i]);
			if(s[i]==',' || s[i]=='.' || s[i]=='!' || s[i]=='(' || s[i]==')' || s[i]==';' || s[i]=='?'){
				s[i]=' ';
			}
		}
		stringstream ss(s);string z;
		while(ss>>z){
			if(m.count(z)){
				cout<<m[z]<<"\n";
				break;
			}
		}
	}
	return 0;
}
