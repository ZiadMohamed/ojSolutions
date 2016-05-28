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
const ll mod=1000000007;

char str[10004], nxt[10004];
ll memo[10004][27];
int n;

ll solve(int ind,int prv){
    if(ind==n)return 1;

    ll &ret=memo[ind][prv];
    if(ret!=-1)return ret;

    ret=0;
    if(str[ind]=='?'){
        if(prv!=26)ret=(ret+solve(ind+1,prv))%mod;
        if(prv!=nxt[ind] && nxt[ind]!=26)ret=(ret+solve(ind+1,nxt[ind]))%mod;
    }
    else ret=(ret+solve(ind+1,str[ind]-'a'))%mod;

    return ret%mod;
}

int main()
{
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",str);
        n=strlen(str);

        char c=26;
        for(int i=n-1;i>=0;--i){
            nxt[i]=c;
            if(str[i]!='?')c=str[i]-'a';
        }

        mem(memo,-1);
        printf("%lld\n",solve(0,26));

    }
    return 0;
}
