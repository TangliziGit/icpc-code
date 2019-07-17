#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+20, maxm=10000*2+20, INF=1e8;
struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):
        from(u), to(v), cap(c), flow(f) {}
};
struct DisEdge{
    int to, nxt, cap;
    DisEdge(int to=0, int nxt=0, int cap=0):
        to(to), nxt(nxt), cap(cap){}
}edges[maxm];
struct Dinic{
    int n, m, s, t;
    vector<int> G[maxn];
    vector<Edge> edges;
    bool vis[maxn];
    int dep[maxn], cur[maxn];
    void init(int n){
        this->n=n;
        for (int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }
    void addEdge(int from, int to, int cap){
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));  // youxiangtu
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool bfs(void){
        memset(vis, false, sizeof(vis));
        queue<int> Q;
        vis[s]=true;
        dep[s]=0;

        Q.push(s);
        while(!Q.empty()){
            int x=Q.front(); Q.pop();
            for(unsigned long i=0;i<G[x].size();i++){
                Edge &e=edges[G[x][i]];
                if(!vis[e.to] && e.cap>e.flow){
                    vis[e.to]=1;
                    dep[e.to]=dep[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int dfs(int x, int a){
        if(x==t || a==0)return a;
        int flow=0, f;
        for(int &i=cur[x];i<G[x].size();i++) {
            Edge &e=edges[G[x][i]];
            if(dep[e.to]==dep[x]+1 && (f=dfs(e.to, min(a, e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
    int maxFlow(int s, int t){
        this->s=s; this->t=t;

        int flow=0;
        while(bfs()){
            memset(cur, 0, sizeof(cur));
            flow+=dfs(s, INF);
        }
        return flow;
    }
}dinic;

int head[maxn], esize;
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to, int cap){
    edges[esize]=DisEdge(to, head[from], cap);
    head[from]=esize++;
}

int dist[maxn];
bool Bellman(int st, int n){
    bool inq[maxn+5];
    int cnt[maxn+5];
    queue<int> que;
    for (int i=0; i<maxn; i++)
        dist[i]=INF, inq[i]=false, cnt[i]=0;
    dist[st]=0; inq[st]=true; cnt[st]=1;
    
    que.push(st);
    while (que.size()){
        int from=que.front(); que.pop();
        inq[from]=false;

        for (int i=head[from]; i!=-1; i=edges[i].nxt){
            DisEdge &e=edges[i];
            int &to=e.to;

            if (dist[to]<=dist[from]+1) continue;
            dist[to]=dist[from]+1;

            if (inq[to]) continue;
            inq[to]=true; que.push(to);

            if (++cnt[to]>n) return false;
        }
    }
    return true;
}

int main(void){
    int T, n, m;
    int from, to, cap;
    
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        init();
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &from, &to, &cap);
            addEdge(from, to, cap);
            addEdge(to, from, cap);
        }
        
        Bellman(1, n);
        dinic.init(n);
        for (int u=1; u<=n; u++){
            for (int i=head[u]; i!=-1; i=edges[i].nxt){
                if (dist[u]+1==dist[edges[i].to]){
                    printf("%d");
                    dinic.addEdge(u, edges[i].to, edges[i].cap);
                }
            }
        }
        printf("%d\n", dinic.maxFlow(1, n));
    }

    return 0;
}

