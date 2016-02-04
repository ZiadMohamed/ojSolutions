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

int check(int x,int y,int cur){
	int i=cur,j=0;
	while(i<arr[x].size() && j<arr[y].size()){
		if(arr[x][i]!=arr[y][j])return -2;
		++i;++j;
	}
	if(j==int(arr[y].size()))return -1;
	return j;
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
		for(int j=0;j<m;++j){
			if(i==j || check(i,j,0)!=-1)continue;
			q.push(state(arr[j],i,arr[j].size()));
			dist[i][arr[j].size()]=arr[j];
			vis[i][arr[j].size()]=tst;
		}
	}

	while(!q.empty()){
		string cost=q.top().cost;
		int ind=q.top().ind, cur=q.top().cur;
		q.pop();

		if(cur==int(arr[ind].size()))return cost;

		for(int i=0;i<m;++i){
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


		for(int i=0;i<ans.size();i+=20)cout<<ans.substr(i,20)<<"\n";
		cout<<"\n";
	}
	return 0;
}
