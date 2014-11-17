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

int memo[20000007];

int solve(int x){
    if(x==1)return 0;

    int &ret=memo[x];
    if(ret!=-1)return ret;

    ret=solve(x-1)+1;
    if(x%2==0)ret=min(ret,solve(x/2)+1);
    if(x%3==0)ret=min(ret,solve(x/3)+1);

    return ret;
}

int main()
{
    mem(memo,-1);
    for(int i=1;i<=20000000;i++)solve(i);
    int t,n;scanf("%d",&t);
    for(int cs=1;cs<=t;++cs){
        scanf("%d",&n);
        printf("Case %d: %d\n",cs,solve(n));
    }
    return 0;
}