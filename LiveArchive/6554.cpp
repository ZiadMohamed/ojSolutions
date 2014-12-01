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

int a[1005],b[1005],n1,n2;

void add(int x){
	for(int i=0;;i++){
		if(i%2==0){
			int pos=x%n1;
			if(a[pos]==-1){a[pos]=x;return;}
			else swap(x,a[pos]);
		}
		else{
			int pos=x%n2;
			if(b[pos]==-1){b[pos]=x;return;}
			else swap(x,b[pos]);
		}
	}
}

int main()
{
	int m,x,cs=0;
	while(cin>>n1>>n2>>m){
		if(n1==0 && n2==0){
			if(m==0)break;
		}
		mem(a,-1);mem(b,-1);
		while(m--){
			cin>>x;
			add(x);
		}
		vector<pair<int,int> > x,y;
		for(int i=0;i<n1;i++){
			if(a[i]!=-1)x.pb(mp(i,a[i]));
		}
		for(int i=0;i<n2;i++){
			if(b[i]!=-1)y.pb(mp(i,b[i]));
		}
		sort(all(x));sort(all(y));
		cout<<"Case "<<++cs<<":\n";
		if(!x.empty()){
			cout<<"Table 1\n";
			for(auto &o:x)cout<<o.f<<":"<<o.s<<"\n";
		}
		if(!y.empty()){
			cout<<"Table 2\n";
			for(auto &o:y)cout<<o.f<<":"<<o.s<<"\n";
		}
	}
	return 0;
}
