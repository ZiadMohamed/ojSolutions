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

char arr[105][105];
int vis[105][105];

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int n,m,cnt;

bool valid(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m)return 0;
	return 1;
}


void rec(int x,int y){
	if(!valid(x,y) || arr[x][y]=='X' || vis[x][y]==cnt)return;
	if(arr[x][y]!='D'){arr[x][y]++;return;}
	vis[x][y]=cnt;
	for(int i=0;i<4;i++){
		rec(x+dx[i],y+dy[i]);
	}
}

int main()
{
	int t;cin>>t;
	mem(vis,0);
	while(t--){
		cnt=0;
		cin>>m>>n;
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>arr[i][j];

		int q;cin>>q;
		while(q--){
			int x,y;cin>>y>>x;
			cnt++;
			rec(x,y);
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<arr[i][j];
			}
			cout<<"\n";
		}
	}
	return 0;
}
