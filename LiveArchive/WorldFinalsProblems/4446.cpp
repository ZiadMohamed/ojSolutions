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

char gateType[22];
int gateVal[22], outp[22];
vector<pair<char,int> > from[22];
vector<vector<int> > observ;
int n,g,u;
int ind, bad, prob;

int getVal(int gate){
	if(gateVal[gate]!=-1)return gateVal[gate];

	int &ret=gateVal[gate];
	if(gateType[gate]=='n'){
		if(from[gate][0].f=='i')ret=!observ[ind][from[gate][0].s-1];
		else ret=!getVal(from[gate][0].s);
	}
	else{
		int a=-1,b=-1;
		for(int i=0;i<2;++i){
			if(from[gate][i].f=='i'){
				if(!i)a=observ[ind][from[gate][i].s-1];
				else b=observ[ind][from[gate][i].s-1];
			}
			else{
				if(!i)a=getVal(from[gate][i].s);
				else b=getVal(from[gate][i].s);
			}
		}

		if(gateType[gate]=='a')ret=a&b;
		else if(gateType[gate]=='o')ret=a|b;
		else ret=a^b;
	}


	if(gate==bad){
		if(prob==0)ret=!ret;
		else if(prob==1)ret=0;
		else if(prob==2)ret=1;
	}

	return ret;
}

bool simulate(){
	mem(gateVal,-1);

	for(int i=1;i<=g;++i)
		getVal(i);

	for(int i=0;i<u;++i)
		if(gateVal[outp[i]]!=observ[ind][i+n])return 0;

	return 1;
}

bool ok(){
	for(ind=0;ind<observ.size();++ind)
		if(!simulate())
			return 0;

	return 1;
}

int main()
{
	int tst=0;
	while(scanf("%d %d %d",&n,&g,&u) && (n || g || u)){
		for(int i=1;i<=g;++i)from[i].clear();

		for(int i=1;i<=g;++i){
			scanf(" %c",&gateType[i]);
			char c;int x;
			for(int j=0;j<2;++j){
				scanf(" %c%d",&c,&x);
				from[i].pb(mp(c,x));
				if(gateType[i]=='n')break;
			}
		}

		for(int i=0;i<u;++i)scanf("%d",&outp[i]);

		int B,in;scanf("%d",&B);
		observ.clear();
		observ.resize(B);

		for(int i=0;i<B;++i){
			for(int j=0;j<n+u;++j){
				scanf("%d",&in);
				observ[i].pb(in);
			}
		}


		printf("Case %d: ",++tst);

		bad=-1;prob=-1;
		if(ok()){
			printf("No faults detected\n");
			continue;
		}

		int wGate=-1, wProb=-1;
		bool found=1;
		for(bad=1;bad<=g && found;++bad){
			for(prob=0;prob<3;++prob){
				if(!ok())continue;
				if(wGate==-1 && wProb==-1){
					wGate=bad;wProb=prob;
				}
				else {found=0;break;}
			}
		}

		if(!found)printf("Unable to totally classify the failure\n");
		else{
			printf("Gate %d is failing; ",wGate);
			if(wProb==0)printf("output inverted\n");
			else if(wProb==1)printf("output stuck at 0\n");
			else printf("output stuck at 1\n");
		}

	}
	return 0;
}
