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

map<int,int> fact(int x){
	map<int,int> m;
	for(int i=2;i*i<=x;++i){
		while(x%i==0)x/=i,++m[i];
	}
	if(x!=1)++m[x];
	return m;
}

int main()
{
	int t;cin>>t;
	while(t--){
		int n,A,B;cin>>n>>A>>B;
		map<int,int> v=fact(A*B),prev=fact(B);
		n-=2;
		while(n--){
			map<int,int> tmp=v;
			for(auto it=prev.begin();it!=prev.end();++it)v[it->f]+=it->s;
			prev=tmp;
		}
		for(auto it=v.begin();it!=v.end();++it){
			cout<<it->f<<" "<<it->s<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
