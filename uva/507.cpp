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
	int t,r=0;cin>>t;
	while(t--){
		int n,in,sum=0,mx=0,a=1,dif=-1,x=0,y=0;cin>>n;
		for(int i=1;i<n;++i){
			cin>>in;
			sum+=in;
			if(sum<0)a=i+1,sum=0;
			if(sum>mx){
				mx=sum;
				dif=i-a;
				x=a;y=i;
			}
			else if(sum==mx && i-a>dif){
				dif=i-a;
				x=a;y=i;
			}
		}
		if(mx<=0){
			cout<<"Route "<<++r<<" has no nice parts\n";
			continue;
		}
		cout<<"The nicest part of route "<<++r<<" is between stops "<<x<<" and "<<y+1<<"\n";
	}
	return 0;
}
