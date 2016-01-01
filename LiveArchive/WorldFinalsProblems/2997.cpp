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

int arr[404][13][32];
int Y1,M1,D1,Y2,M2,D2;

int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool leap(int yr){
	return ((yr%4==0 && yr%100!=0) || (yr%400==0));
}


void fillDays(bool c){
	for(int y=Y1;y<=Y2;++y){
		int a=(y==Y1)?M1:1;
		int b=(y==Y2)?M2:12;

		for(int m=a;m<=b;++m){
			int aa=(y==Y1 && m==a)?D1:1;
			int bb=(y==Y2 && m==b)?D2:month[m]+(m==2 && leap(y));

			for(int d=aa;d<=bb;++d)
				if(!arr[y-1700][m][d])
					arr[y-1700][m][d]=1+c;
		}
	}
}

int main()
{
	int n,m,tst=0;
	while(scanf("%d %d",&n,&m) && n+m){
		int mn=3000,mx=0;
		for(int i=0;i<n+m;++i){
			scanf("%04d%02d%02d %04d%02d%02d",&Y1,&M1,&D1,&Y2,&M2,&D2);
			mn=min(mn,Y1);
			mx=max(mx,Y2);
			fillDays((i>=n));
		}

		if(tst)printf("\n");
		printf("Case %d:\n",++tst);

		bool quote=0;
		int prevY=-1,prevM=-1,prevD=-1;
		int curY=-1,curM=-1,curD=-1;
		for(int i=mn;i<=mx;++i){
			bool lp=leap(i);
			for(int j=1;j<=12;++j){
				for(int k=1;k<=month[j]+(j==2 && lp);++k){
					if(arr[i-1700][j][k]==2){
						if(prevY==-1)prevY=i,prevM=j,prevD=k;
						curY=i,curM=j,curD=k;
					}
					else{
						if(prevY!=-1){
							printf("    %d/%d/%d",prevM,prevD,prevY);
							if(prevY!=curY || prevM!=curM || prevD!=curD)
								printf(" to %d/%d/%d",curM,curD,curY);
							printf("\n");
							prevY=-1,prevM=-1,prevD=-1;
							curY=-1,curM=-1,curD=-1;
							quote=1;
						}
					}
				}
			}
		}

		if(prevY!=-1){
			printf("    %d/%d/%d",prevM,prevD,prevY);
			if(prevY!=curY || prevM!=curM || prevD!=curD)
				printf(" to %d/%d/%d",curM,curD,curY);
			printf("\n");
			quote=1;
		}


		if(!quote)
			printf("    No additional quotes are required.\n");


		mem(arr,0);
	}
	return 0;
}
