#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
const int MAXM=1000;
const int INF=0x3f3f3f3f;

int g[MAXM+5][MAXM+5],dist[MAXM+5],n,m;
bool vis[MAXM+5];

void spfa(int s,int p){
    int i;
    memset(dist,-1,sizeof(dist));
    dist[s]=INF;
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vis[u]=0;
        for(i=1;i<=n;i++){
            int t=dist[u]<g[u][i]?dist[u]:g[u][i];
            if(i!=u&&g[u][i]!=-1&&dist[i]<t){
                dist[i]=t;
                if(!vis[i]){
                    q.push(i);
                    vis[i]=1;
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
            scanf("%d%d",&n,&m);
            memset(g,-1,sizeof(g));
            for(i=1;i<=m;i++){
                int a,b,v;
                scanf("%d%d%d",&a,&b,&v);
                if(g[a][b]<v){
                    g[a][b]=g[b][a]=v;
                }
            }
            printf("Scenario #%d:\n",q);
            spfa(1,n);
        }
    }
    return 0;
}
