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
	while(cin>>n && n!=-1){
		int sum=1;vector<int> v;v.pb(1);
		for(int i=2;i*i<=n;++i){
			if(i*i==n){
				sum+=i;
				v.pb(i);
				continue;
			}
			if(n%i==0)sum+=(i+(n/i)),v.pb(i),v.pb(n/i);
		}
		if(sum==n){
			sort(all(v));
			cout<<n<<" ";
			for(int i=0;i<v.size();i++){
				if(i==0)cout<<"= ";
				else cout<<"+ ";
				cout<<v[i];
				if(i<v.size()-1)cout<<" ";
			}
			cout<<"\n";
		}
		else{
			cout<<n<<" is NOT perfect.\n";
		}
	}
	return 0;
}
