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

int m, tst;
string arr[23];

int visCheck[23][23][23];
int visB[23][23][23];

int check(int x,int y,int cur){
	if(visB[x][y][cur]==tst)return visCheck[x][y][cur];

	visB[x][y][cur]=tst;
	int i=cur,j=0;
	while(i<arr[x].size() && j<arr[y].size()){
		if(arr[x][i]!=arr[y][j])return visCheck[x][y][cur]=-2;
		++i;++j;
	}
	if(j==int(arr[y].size()))return visCheck[x][y][cur]=-1;
	return visCheck[x][y][cur]=j;
}

struct state{
	string cost;
	int ind, cur;
	state(string cost,int ind,int cur){
		this->cost=cost;
		this->ind=ind;
		this->cur=cur;
	}
	bool operator<(const state &st) const{
		if(cost.size()==st.cost.size())return cost>st.cost;
		return cost.size()>st.cost.size();
	}
};

string dist[23][23];
int vis[23][23];

string dijkstra(){

	priority_queue<state> q;

	for(int i=0;i<m;++i){
		q.push(state("",i,0));
		dist[i][0]="";
		vis[i][0]=tst;
	}

	while(!q.empty()){
		string cost=q.top().cost;
		int ind=q.top().ind, cur=q.top().cur;
		q.pop();

		if(cur==int(arr[ind].size()))return cost;

		for(int i=0;i<m;++i){
			if(i==ind && !cur)continue;
			int c=check(ind,i,cur);
			if(c==-2)continue;

			int newInd, newCur;
			string newCost;
			if(c==-1)newInd=ind, newCur=cur+arr[i].size(), newCost=cost+arr[i];
			else newInd=i, newCur=c, newCost=cost+arr[ind].substr(cur);

			if(vis[newInd][newCur]!=tst || (newCost.size()<dist[newInd][newCur].size()) ||
					(newCost.size()==dist[newInd][newCur].size() && newCost<dist[newInd][newCur])){

				vis[newInd][newCur]=tst;
				dist[newInd][newCur]=newCost;
				q.push(state(newCost,newInd,newCur));
			}
		}
	}
	return "?";
}


int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	while(cin>>m && m){

		for(int i=0;i<m;++i)
			cin>>arr[i];


		++tst;

		string ans=dijkstra();


		cout<<"Code "<<tst<<": "<<ans.size()<<" bits\n";


		for(int i=0,ii=0;i<ans.size();++i,++ii){
			if(ii==20)cout<<"\n",ii=0;
			cout<<ans[i];
		}
		cout<<"\n\n";
	}
	return 0;
}
