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

string arr[11];
int dig[11];
int assi[30];
int lett[11];
bool exist[30];
bool lead[30];

int main()
{
	int n;
	while(cin>>n){
		for(int i=0;i<10;++i)dig[i]=i;
		mem(exist,0);mem(lead,0);

		int ans=0,sz=0;
		for(int i=0;i<n;++i){
			cin>>arr[i];
			lead[arr[i][0]-'A']=1;
			for(int j=0;j<arr[i].size();++j){
				if(!exist[arr[i][j]-'A'])lett[sz++]=arr[i][j]-'A',exist[arr[i][j]-'A']=1;
			}
		}

		do{
			bool ok=1;
			for(int i=0;i<sz;++i){
				assi[lett[i]]=dig[i];
				if(lead[lett[i]] && !dig[i]){ok=0;break;}
			}

			if(!ok){
				sort(dig+sz,dig+10);
				reverse(dig+sz,dig+10);
				continue;
			}

			ll sum=0;
			for(int i=0;i<n-1;++i){
				ll x=0;
				for(int j=0;j<arr[i].size();++j)x=(x*10LL)+assi[arr[i][j]-'A'];
				sum+=x;
			}

			if(sum==0){
				if(arr[n-1].size()==1 && assi[arr[n-1][0]-'A']==0)++ans;
				sort(dig+sz,dig+10);
				reverse(dig+sz,dig+10);
				continue;
			}

			int ind=arr[n-1].size()-1;
			bool check=1;
			while(sum>0){
				if(sum%10!=assi[arr[n-1][ind]-'A']){check=0;break;}
				--ind;
				sum/=10;
				if((ind>=0 && sum>0) || (ind<0 && !sum))continue;
				check=0;break;
			}
			if(check)++ans;

			sort(dig+sz,dig+10);
			reverse(dig+sz,dig+10);
		}
		while(next_permutation(dig,dig+10));
		cout<<ans<<"\n";
	}
	return 0;
}
