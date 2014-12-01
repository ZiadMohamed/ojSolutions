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
	int n;
	while(cin>>n && n!=0){
		int sms=0;
		vector<int> v(4,0);
		map<string,bool> m;
		set<string> st;
		for(int cs=0;cs<n;++cs){
			string s;cin>>s;
			int pos=s.find(':');
			string z=s.substr(pos+1);
			bool bad=0;
			if(z.size()!=1)bad=1;
			if(!bad && (z[0]<'1' || z[0]>'4'))bad=1;

			s=s.substr(0,pos);
			for(int i=1;i<s.size();i++)if(!isdigit(s[i]))s.erase(s.begin()+i),--i;
			if(s[0]=='0' || s[0]=='(')s.erase(0,1),s="+98"+s;
			else if(isdigit(s[0]))s="+9821"+s;

			st.insert(s);
			if(!m[s] && !bad){
				m[s]=1;++sms;
				++v[z[0]-'0'-1];
			}
		}
		for(auto &x:v){
			cout<<x*100/sms<<"%\n";
		}
		cout<<"Participants:"<<st.size()<<"\n";
	}
	return 0;
}
