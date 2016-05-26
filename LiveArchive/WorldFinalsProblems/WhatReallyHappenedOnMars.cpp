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

int strt[22], basep[22], currentp[22], instructSz[22], instructidx[22];
int ceiling[22], maxCeiling[22], ans[22];
bool Lock[22][22], vis[22];
pair<char,int> instruct[22][102];


int main()
{
    int t,r;scanf("%d %d",&t,&r);
    for(int i=0;i<t;++i){
        scanf("%d %d %d",strt+i,basep+i,instructSz+i);

        for(int j=0;j<instructSz[i];++j){
            scanf(" %c%d",&instruct[i][j].f,&instruct[i][j].s);
            if(instruct[i][j].f!='C')--instruct[i][j].s;

            if(instruct[i][j].f=='L')
                ceiling[instruct[i][j].s]=max(ceiling[instruct[i][j].s],basep[i]);
        }

    }

        int tm=0, cnt=0;
        while(cnt<t){
            priority_queue< pair<int,int> > q;

            for(int i=0;i<t;++i)
                if(strt[i]<=tm && instructidx[i]!=instructSz[i])
                    q.push(mp(basep[i],i));


            for(int i=0;i<t;++i){
                maxCeiling[i]=0;
                for(int j=0;j<r;++j)
                    if(Lock[i][j])
                        maxCeiling[i]=max(maxCeiling[i],ceiling[j]);
            }

            for(int i=0;i<t;++i)currentp[i]=basep[i];

            mem(vis,0);
            int task=-1;
            while(!q.empty()){
                int curTask=q.top().s;
                q.pop();
                if(vis[curTask])continue;
                vis[curTask]=1;

                bool blocked=0;
                int ind=instructidx[curTask];
                for(int i=0;i<t;++i){
                    if(i==curTask)continue;

                    if(instruct[curTask][ind].f=='L' &&
                            (Lock[i][instruct[curTask][ind].s] || maxCeiling[i]>=currentp[curTask])){

                        currentp[i]=max(currentp[i],currentp[curTask]);
                        blocked=1;
                        q.push(mp(currentp[i],i));
                    }

                }
                if(!blocked){task=curTask;break;}
            }


            if(task==-1){++tm;continue;}

            int ind=instructidx[task];
            if(instruct[task][ind].f=='C'){
                --instruct[task][ind].s;
                if(instruct[task][ind].s<=0)++instructidx[task];

                ++tm;
            }
            else if(instruct[task][ind].f=='L')
                Lock[task][instruct[task][ind].s]=1, ++instructidx[task];

            else
                Lock[task][instruct[task][ind].s]=0, ++instructidx[task];



            if(instructidx[task]==instructSz[task])ans[task]=tm, ++cnt;
    }
    for(int i=0;i<t;++i)printf("%d\n",ans[i]);
    return 0;
}
