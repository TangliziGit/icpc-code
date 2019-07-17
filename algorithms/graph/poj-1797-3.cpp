#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
#define min(a,b) a<b?a:b
const int INF=0x3f3f3f3f;
using namespace std;
typedef pair<int,int> pii;

struct cmp{
    bool operator()(pii a,pii b){
        return a.first<b.first;
    }
};

int g[1005][1005],n,m,dist[1005];

void dij(int s,int p){
    int i;
    memset(dist,-1,sizeof(dist));
    dist[s]=INF;
    priority_queue<pii,vector<pii>,cmp>q;
    q.push(make_pair(dist[s],s));
    while(!q.empty()){
        pii u=q.top();
        q.pop();
        if(u.first<dist[u.second])continue;
        for(i=1;i<=n;i++){
            if(~g[u.second][i]){
                int j=min(u.first,g[u.second][i]);
                if(dist[i]==-1||dist[i]<j){
                    dist[i]=j;
                    q.push(make_pair(dist[i],i));
                }
            }
        }
    }
    printf("%d\n\n",dist[p]);
}

int main(){
    int t;
    while(scanf("%d",&t)!=EOF){
        for(int q=1;q<=t;q++){
            int i;
            memset(g,-1,sizeof(g));
            scanf("%d%d",&n,&m);
            for(i=1;i<=m;i++){
                int x,y,v;
                scanf("%d%d%d",&x,&y,&v);
                if(g[x][y]<v){
                    g[x][y]=g[y][x]=v;
                }
            }
            printf("Scenario #%d:\n",q);
            dij(1,n);
        }
    }
    return 0;
}
