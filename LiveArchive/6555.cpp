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

bool vis[30];
char arr[7][7];
pair<int,int> ind[30];
string ans;

void fill(int x,int y){
	bool first=1;
	char c='A';
	for(int i=x;i<5;i++){
		if(!first)y=0;
		for(int j=y;j<5;j++){
			while(c<='Z'){
				if(!vis[c-'A'])break;
				c++;
			}
			arr[i][j]=c;
			c++;
			if(c=='J')c++;
		}
		first=0;
	}
}



void add(char a,char b){
	char x,y;
	pair<int,int> p1=ind[a-'A'],p2=ind[b-'A'];
	if(p1.f==p2.f){
		x=arr[p1.f][(p1.s+1)%5];
		y=arr[p2.f][(p2.s+1)%5];
	}
	else if(p1.s==p2.s){
		x=arr[(p1.f+1)%5][p1.s];
		y=arr[(p2.f+1)%5][p2.s];
	}
	else{
		x=arr[p1.f][p2.s];
		y=arr[p2.f][p1.s];
	}
	ans+=x;
	ans+=y;
}

int main()
{
	string a,b;
	int t,cs=0;cin>>t;
	getline(cin,a);
	while(t--){
		ans.clear();
		mem(vis,0);
		mem(arr,0);
		mem(ind,-1);
		getline(cin,a);for(int i=0;i<a.size();i++)a[i]=toupper(a[i]);
		getline(cin,b);
		for(int i=0;i<b.size();i++){
			if(!isalpha(b[i]))b.erase(b.begin()+i),i--;
			else b[i]=toupper(b[i]);
		}

		int pos=0;bool check=0;

		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				while(pos<a.size()){
					if(isalpha(a[pos]) && !vis[a[pos]-'A'])break;
					pos++;
				}
				if(pos==a.size()){fill(i,j);check=1;break;}
				if(a[pos]=='J')arr[i][j]='I',vis['J'-'A']=1,vis['I'-'A']=1;
				else arr[i][j]=a[pos];
				vis[a[pos]-'A']=1;
				if(a[pos]=='I')vis['J'-'A']=1;
				pos++;
			}
			if(check)break;
		}

		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				ind[arr[i][j]-'A']=mp(i,j);
			}
		}

		char f='A';

		for(int i=0;i<b.size();i++){
			if(i+1<b.size()){
				if(b[i+1]!=b[i]){add(b[i],b[i+1]);i++;continue;}
			}
			for(char c=f;;c++){
				if(c=='J')c++;
				if(c!=b[i]){
					add(b[i],c);
					if(c=='Z')f='A';
					else f=c+1;
					break;
				}
				if(c=='Z')c='A',c--;
			}
		}
		cout<<"Case "<<++cs<<": "<<ans<<"\n";
	}
	return 0;
}
