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

int arr[51];

int main()
{
	int n,cs=0;
	while(cin>>n && n!=0){

		int avg=0,ans=0;
		for(int i=0;i<n;++i)cin>>arr[i],avg+=arr[i];
		avg/=n;

		for(int i=0;i<n;++i)if(arr[i]<avg)ans+=avg-arr[i];

		cout<<"Set #"<<++cs<<"\n";
		cout<<"The minimum number of moves is "<<ans<<".\n\n";

	}
	return 0;
}
