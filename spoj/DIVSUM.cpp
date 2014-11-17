#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ans[500009];
int main()
{
	memset(ans,0,sizeof(ans));ans[1]=-1;
	int t,n,mx=500000;scanf("%d",&t);
	for(int i=2;i<=mx;i++){
		for(int j=i*2;j<=mx;j+=i){
			ans[j]+=i;
		}
	}
	while(t--){
		scanf("%d",&n);
		printf("%d\n",ans[n]+1);
	}
	return 0;
}
