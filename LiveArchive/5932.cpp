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

bool arr[27];

int main()
{
	string s;
	while(getline(cin,s) && s!="END"){
		mem(arr,0);
		bool check=1;
		for(char x:s){
			if(x==' ')continue;
			if(arr[x-'A']){check=0;break;}
			arr[x-'A']=1;
		}
		if(check)cout<<s<<"\n";
	}
	return 0;
}
