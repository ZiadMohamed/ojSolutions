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

struct node{
	char abo1,abo2;
	char rh1,rh2;
	node(char abo1,char abo2,char rh1,char rh2){
		this->abo1=abo1;this->abo2=abo2;
		this->rh1=rh1;this->rh2=rh2;
	}
};
vector<pair<char,char> > genAll(node x){
	return vector<pair<char,char> >{mp(x.abo1,x.rh1),mp(x.abo1,x.rh2),mp(x.abo2,x.rh1),mp(x.abo2,x.rh2)};
}

map<string, vector<node> > m;
map<string,string> combToBlood;


set<string> reproduce(node x,node y){
	vector<pair<char,char> > a=genAll(x), b=genAll(y);
	set<string> ret;
	for(int i=0;i<a.size();++i){
		for(int j=0;j<b.size();++j){
			string tmp;
			tmp+=min(a[i].f,b[j].f);tmp+=max(a[i].f,b[j].f);
			tmp=combToBlood[tmp];

			if(a[i].s==b[j].s)tmp+=a[i].s;
			else tmp+='+';

			ret.insert(tmp);
		}
	}
	return ret;
}

string comb[]={"AA","AB","AO","BB","BO","OO"};
string blood[]={"A","AB","A","B","B","O"};
string all[]={"A+","A-","AB+","AB-","B+","B-","O+","O-"};

string par1,par2,child;
set<string> ans;

bool solve(){
	vector<node> a=m[par1],b=m[par2];

	for(int i=0;i<a.size();++i){
		for(int j=0;j<b.size();++j){
			set<string> res=reproduce(a[i],b[j]);
			if(child!="?"){
				if(res.count(child))return 1;
			}
			else ans.insert(all(res));
		}
	}
	return 0;
}

void printSet(){
	if(ans.empty()){
		cout<<"IMPOSSIBLE";
		return;
	}
	if(ans.size()==1){
		cout<<*(ans.begin());
		return;
	}

	cout<<"{";
	bool f=1;
	for(set<string>::iterator it=ans.begin();it!=ans.end();++it){
		if(!f)cout<<", ";
		else f=0;
		cout<<*(it);
	}
	cout<<"}";
}

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(int i=0;i<6;++i){
		combToBlood[comb[i]]=blood[i];

		m[blood[i]+"+"].pb(node(comb[i][0],comb[i][1],'+','-'));
		m[blood[i]+"+"].pb(node(comb[i][0],comb[i][1],'+','+'));

		m[blood[i]+"-"].pb(node(comb[i][0],comb[i][1],'-','-'));
	}

	int tst=0;
	while(cin>>par1>>par2>>child && par1!="E"){
		if(child=="?")solve();
		else{
			bool f=0;
			if(par1=="?")swap(par1,par2),f=1;
			for(int i=0;i<8;++i){
				par2=all[i];
				if(solve())ans.insert(par2);
			}
			par2="?";
			if(f)swap(par1,par2);
		}

		cout<<"Case "<<++tst<<": ";
		if(par1!="?")cout<<par1;
		else printSet();
		cout<<" ";
		if(par2!="?")cout<<par2;
		else printSet();
		cout<<" ";
		if(child!="?")cout<<child;
		else printSet();

		cout<<"\n";
		ans.clear();
	}

	return 0;
}
