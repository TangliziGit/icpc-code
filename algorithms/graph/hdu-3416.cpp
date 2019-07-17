#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e3+10, maxm=1e5+10, INF=0x3f3f3f3f;
struct Edge{
    int to, dis, next;
    Edge(int to=0, int dis=0, int next=0):
        to(to), dis(dis), next(next) {}
}edges[maxm+5];
struct FlowEdge{
    int from, to, cap, flow, next;
    FlowEdge(int from=0, int to=0, int cap=0, int next=0):
        from(from), to(to), cap(cap), next(next) {}
}fedges[maxm+5];
int head[maxn+5], fhead[maxn+5], esize, fsize, dis[2][maxn+5];

void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to, int dis){
    edges[esize]=Edge(to, dis, head[from]);
    head[from]=esize++;
}

bool Bellman(int st, int n, int which){
    bool inq[maxn+5]={false};
    int cnt[maxn+5]={0}, dist[maxn+5];
    stack<int> sta; // queue<int> que; // stack<int> sta;
    memset(dist, INF, sizeof(dist));
    dist[st]=0; inq[st]=true;
    
    sta.push(st); // que.push(st); // sta.push(st);
    while (sta.size()){
        int from=sta.top(); sta.pop();
        inq[from]=false;

        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to;

            if (dist[to]<=dist[from]+e.dis) continue;
            dist[to]=dist[from]+e.dis;

            if (inq[to]) continue;
            inq[to]=true; sta.push(to);// que.push(to);

            if (++cnt[to]>=n) return false;
        }
    }
    memcpy(dis[which], dist, sizeof(dist));
    return true;
}

void finit(void){
    memset(fhead, -1, sizeof(fhead));
    fsize=0;
}

void addFlowEdge(int from, int to, int cap){
    fedges[fsize]=FlowEdge(from, to, cap, fhead[from]);
    fhead[from]=fsize++;
    fedges[fsize]=FlowEdge(to, from, 0, fhead[to]);
    fhead[to]=fsize++;
}

int d[maxn+5], pre[maxn+5], gap[maxn+5], cur[maxn+5];
int sap(int start,int end,int nodenum){
    memset(d,0,sizeof(d));
    memset(gap,0,sizeof(gap));
    memcpy(cur,fhead,sizeof(fhead));
    int u=pre[start]=start,maxflow=0,aug=-1;
    gap[0]=nodenum;
    while(d[start]<nodenum){
        loop:
        for(int &i=cur[u];i!=-1;i=fedges[i].next){
            int v=fedges[i].to;
            if(fedges[i].cap&&d[u]==d[v]+1){
                if(aug==-1||aug>fedges[i].cap)
                    aug=fedges[i].cap;
                pre[v]=u;
                u=v;
                if(v==end){
                    maxflow+=aug;
                    for(u=pre[u];v!=start;v=u,u=pre[u]){
                        fedges[cur[u]].cap-=aug;
                        fedges[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }

        int mind=nodenum;
        for(int i=fhead[u]; i!=-1; i=fedges[i].next){
            int v=fedges[i].to;
            if(fedges[i].cap && mind>d[v]){
                cur[u]=i;
                mind=d[v];
            }
        }
        if((--gap[d[u]])==0) break;
        gap[d[u]=mind+1]++;
        u=pre[u];
    }
    return maxflow;
}

int maxFlow(int st, int tar){
    int flow=0, aug[maxn+5], pre[maxn+5];
    while (true){
        queue<int> que;
        memset(aug, 0, sizeof(aug));
        aug[st]=INF;
        
        que.push(st);
        while (que.size()){
            int from=que.front(); que.pop();

            for (int i=fhead[from]; i!=-1; i=fedges[i].next){
                FlowEdge &e=fedges[i];
                int &to=e.to;

                if (aug[to] || e.cap <= e.flow) continue;
                pre[to]=i;
                aug[to]=min(aug[from], e.cap-e.flow);
                que.push(to);
            }
            if (aug[tar]) break;
        }
        if (!aug[tar]) break;
        for (int to=tar; to!=st; to=fedges[pre[to]].from){
            fedges[pre[to]].flow+=aug[tar];
            fedges[pre[to]^1].flow-=aug[tar];
        }flow+=aug[tar];
    }return flow;
}

int main(void){
    int T, n, m;
    int from[maxm+5], to[maxm+5], di[maxm+5], st, tar;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        init();
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &from[i], &to[i], &di[i]);
            addEdge(from[i], to[i], di[i]);
        }scanf("%d%d", &st, &tar);
        Bellman(st, n, 0);
        
        init();
        for (int i=0; i<m; i++)
            addEdge(to[i], from[i], di[i]);
        Bellman(tar, n, 1);

        finit();
        for (int i=0; i<m; i++)
            if (to[i]!=from[i] && dis[0][from[i]]+dis[1][to[i]]+di[i]==dis[0][tar])
                addFlowEdge(from[i], to[i], 1);
        printf("%d\n", maxFlow(st, tar));//sap(st, tar, n));
    }

    return 0;
}
