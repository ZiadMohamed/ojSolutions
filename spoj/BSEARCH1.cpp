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

int arr[100005];
int n,x;

int BS(){
	int low=0,high=n,pos=-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(x>arr[mid])low=mid+1;
		else pos=(x==arr[mid])?mid:pos,high=mid-1;
	}
	return pos;
}

int main()
{
	int q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;++i)scanf("%d",arr+i);
	while(q--){
		scanf("%d",&x);
		printf("%d\n",BS());
	}
	return 0;
}
