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

int arr[20];

int main()
{
	int p;scanf("%d",&p);
	while(p--){
		int cs,ans=0;scanf("%d",&cs);
		for(int i=0;i<15;i++)scanf("%d",arr+i);
		for(int i=1;i<14;i++){
			for(int j=i;j<14;j++){
				bool check=1;
				for(int k=i;k<=j;k++){
					if(arr[k]<=arr[i-1] || arr[k]<=arr[j+1]){check=0;break;}
				}
				ans+=check;
			}
		}
		printf("%d %d\n",cs,ans);
	}
	return 0;
}
