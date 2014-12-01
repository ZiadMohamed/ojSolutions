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

int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};

vector<string> v;
char cur,gdid;
int cnt;

bool valid(int x,int y){
	if(x<0 || y<0 || x>=v.size() || y>=v[x].size())return 0;
	if(v[x][y]==' ')return 0;
	return 1;
}

void fill(int x,int y){
	if(!valid(x,y) || v[x][y]!=cur)return;
	v[x][y]=gdid;cnt++;
	for(int i=0;i<4;i++){
		int a=x+dx[i],b=y+dy[i];
		fill(a,b);
	}
}
void format(){
	vector<string> z;
	for(int i=0;i<v[0].size();i++){
		string tmp;
		for(int j=v.size()-1;j>=0;j--){
			tmp+=v[j][i];
		}
		z.pb(tmp);
	}
	int m=-1;
	for(int i=0;i<z.size();i++){
		bool check=0;
		int sz=z[i].size();m=sz;
		for(int j=0;j<z[i].size();j++){
			if(z[i][j]=='?')z[i].erase(z[i].begin()+j),j--;
			else if(z[i][j]!=' ')check=1;
		}
		while(z[i].size()<sz)z[i]+=' ';
		if(!check)z.erase(z.begin()+i),i--;
	}
	v.clear();
	for(int i=m-1;i>=0;i--){
		string tmp;
		for(int j=0;j<z.size();j++){
			if(i>=z[j].size())tmp+=' ';
			else tmp+=z[j][i];
		}
		v.pb(tmp);
	}
	string tmp=string(10,' ');
	while(v.size()<12)v.insert(v.begin()+0,tmp);
}

int ind[13]={0,12,11,10,9,8,7,6,5,4,3,2,1};

int main()
{
	int t;
	while(cin>>t){
		if(t==0)break;
		v.resize(12);
		for(int i=0;i<12;i++)cin>>v[i];
		while(t--){
			char c;int x;cin>>c>>x;
			int y=c-'a';
			x=ind[x]-1;
			cur=v[x][y];
			gdid='?';
			cnt=0;
			fill(x,y);
			if(cnt==1 || cnt==2){
				swap(gdid,cur);
				fill(x,y);
			}
			format();
		}
		int ans=0;
		for(int i=0;i<v.size();i++){
			for(int j=0;j<v[i].size();j++)if(v[i][j]!=' ')++ans;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
