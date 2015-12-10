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

pair<string,string> arr[15];
int sz;
int freq[7];

string key;

map<string,vector<string> > scale;

void gen(int pos,string cur,vector<string> v,bool flat,bool sharp,int i){
	if(i)
		v.pb(cur);

	if(i==7){
		if(cur==key){
			mem(freq,0);
			for(int j=0;j<v.size();++j)++freq[v[j][0]-'A'];
			for(int j=0;j<7;++j)if(freq[j]!=1)return;
			scale[key]=v;
		}
		return;
	}
	int j=pos;
	if(i==2 || i==6)j=(j+1)%sz;
	else j=(j+2)%sz;

	string a=arr[j].f,b=arr[j].s;

	if(!(flat && (a.size()>1 && a[1]=='#')) && !(sharp && (a.size()>1 && a[1]=='b')))
		gen(j,a,v,flat|(a.size()>1 && a[1]=='b'),sharp|(a.size()>1 && a[1]=='#'),i+1);

	if(b!="?" && !(flat && (b.size()>1 && b[1]=='#')) && !(sharp && (b.size()>1 && b[1]=='b')))
		gen(j,b,v,flat|(b.size()>1 && b[1]=='b'),sharp|(b.size()>1 && b[1]=='#'),i+1);


}


int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	stringstream ss("C/B# C#/Db D D#/Eb E/Fb F/E# F#/Gb G G#/Ab A A#/Bb B/Cb");
	string tmp;
	while(ss>>tmp){
		int pos=tmp.find('/');
		if(pos==-1)arr[sz++]=mp(tmp,"?");
		else arr[sz++]=mp(tmp.substr(0,pos),tmp.substr(pos+1));
	}
	

	for(int i=0;i<sz;++i){
		key=arr[i].f;
		gen(i,arr[i].f,vector<string>(),(arr[i].f.size()>1 && arr[i].f[1]=='b'),(arr[i].f.size()>1 && arr[i].f[1]=='#'),0);

		if(arr[i].s=="?")continue;
		key=arr[i].s;
		gen(i,arr[i].s,vector<string>(),(arr[i].s.size()>1 && arr[i].s[1]=='b'),(arr[i].s.size()>1 && arr[i].s[1]=='#'),0);
	}


	bool f=1;
	string src,targ,note;
	while(cin>>src && src!="*"){
		cin>>targ;
		vector<string> notes;
		while(cin>>note && note!="*")
			notes.pb(note);

		if(!f)cout<<"\n";
		else f=0;
		if(scale.count(src) && scale.count(targ)){
			cout<<"Transposing from "<<src<<" to "<<targ<<":\n";
			vector<string> v=scale[src];


			for(string str:notes){
				int pos=-1;
				for(int i=0;i<v.size();++i){
					if(v[i]==str){
						pos=i;
						break;
					}
				}
				if(pos==-1)cout<<"  "<<str<<" is not a valid note in the "<<src<<" major scale\n";
				else cout<<"  "<<str<<" transposes to "<<scale[targ][pos]<<"\n";
			}
		}

		else if(!scale.count(src))
			cout<<"Key of "<<src<<" is not a valid major key\n";

		else if(!scale.count(targ))
			cout<<"Key of "<<targ<<" is not a valid major key\n";

	}
	return 0;
}
