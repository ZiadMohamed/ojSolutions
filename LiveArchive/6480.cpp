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

int arr[21];

int main()
{
	int t;cin>>t;
	while(t--){
		for(int i=0;i<20;++i)cin>>arr[i];
		for(int i=19;i>0;--i){
			arr[i-1]+=arr[i]/2;
			if(arr[i]%2)arr[i]=1;
			else arr[i]=0;
		}
		for(int i=0;i<19;++i)cout<<arr[i]<<" ";
		cout<<arr[19]<<"\n";
	}
	return 0;
}
