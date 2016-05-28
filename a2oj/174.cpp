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

char a[1003], b[1003];
int memo[1003][1003], n, m;

int solve(int x,int y){
    if(x==n && y==m)return 0;

    int &ret=memo[x][y];
    if(ret!=-1)return ret;

    ret=1e6;

    if(x<n && y<m && a[x]==b[y])
        ret=min(ret,solve(x+1,y+1));

    if(x<n)ret=min(ret,solve(x+1,y)+15);
    if(y<m)ret=min(ret,solve(x,y+1)+30);

    return ret;
}

int main()
{
    while(true){
        mem(a,0);mem(b,0);
        scanf("%s",a);n=strlen(a);
        if(n==1 && a[0]=='#')break;
        scanf("%s",b);m=strlen(b);

        mem(memo,-1);

        printf("%d\n",solve(0,0));
    }
    return 0;
}
