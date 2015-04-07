#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <climits>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pi acos(-1.0)
#define EPS 1e-9
typedef long long ll;

using namespace std;


int main()
{
	int t;
	while(cin>>t && t!=0){
		double n=t;
		for(double a=0.0;a<=n;a+=0.5){
			for(double b=0.0;b<=n;b+=0.5){
				for(double c=0.0;c<=n;c+=0.5){
					if((c*(5.0))+ b+b +a==n){
						if(fabs(b-c)<=0.5){
							cout<<fixed<<setprecision(1)<<a<<" "<<b<<" "<<b<<" "<<c<<"\n";
							goto end;
						}
					}
				}
			}
		}
		end:;
	}
	return 0;
}
