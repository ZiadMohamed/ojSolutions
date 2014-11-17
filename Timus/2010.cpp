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

int dx[8]={1,0,0,-1,1,-1,1,-1};
int dy[8]={0,1,-1,0,1,-1,-1,1};

int DX[8]={2,2,-2,-2,1,-1,1,-1};
int DY[8]={1,-1,1,-1,2,2,-2,-2};

int n;
bool valid(int x,int y){
	if(x<1 || y<1 || x>n || y>n)return 0;
	return 1;
}

int king(int x,int y){
	int cnt=0;
	for(int i=0;i<8;i++){
		int a=x+dx[i],b=y+dy[i];
		if(valid(a,b))++cnt;
	}
	return cnt;
}

int knight(int x,int y){
	int cnt=0;
	for(int i=0;i<8;i++){
		int a=x+DX[i],b=y+DY[i];
		if(valid(a,b))++cnt;
	}
	return cnt;
}

ll bishop(int x,int y){
	ll a=n-max(x,y);
	ll b=min(x,y)-1;
	ll c=min(n-x,y-1);
	ll d=min(x-1,n-y);
	return a+b+c+d;
}

ll rook(int x,int y){
	ll tmp=(ll)n+(ll)n;tmp-=2LL;
	return tmp;
}

int main()
{
	int x,y;cin>>n>>x>>y;
	cout<<"King: "<<king(x,y)<<"\n";
	cout<<"Knight: "<<knight(x,y)<<"\n";
	cout<<"Bishop: "<<bishop(x,y)<<"\n";
	cout<<"Rook: "<<rook(x,y)<<"\n";
	cout<<"Queen: "<<rook(x,y)+bishop(x,y)<<"\n";
	return 0;
}
