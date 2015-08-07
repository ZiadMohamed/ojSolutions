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

int arr[257];

int main()
{
	string keyb="qwertyuiop[]asdfghjkl;'zxcvbnm,./";
	for(int i=0;i<keyb.size();++i)arr[int(keyb[i])]=i;

	string in,s;
	getline(cin,in);
	stringstream ss(in);

	bool f=1;
	while(ss>>s){
		if(!f)putchar(' ');
		else f=0;

		for(int i=0;i<s.size();++i){
			char c=tolower(s[i]);
			int pos=arr[int(c)]-2;

			if(pos<0 || !isalpha(keyb[pos]))putchar(' ');
			else if(isupper(s[i]))putchar(toupper(keyb[pos]));
			else putchar(keyb[pos]);
		}
	}
	putchar('\n');
	return 0;
}
