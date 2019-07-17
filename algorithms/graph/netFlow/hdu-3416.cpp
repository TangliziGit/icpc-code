#define E (edges[i])
#define NE (edges[i^1])
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1000+20, maxm=(100000+200)*3;
const int INF=5e6;
struct Edge{
    int to, nxt, from, cap, flow;
    Edge(int to=0, int nxt=-1, int from=0, int cap=0):
        to(to), nxt(nxt), from(from), cap(cap), flow(0) {}
}edges[maxm];
int head[maxn], fhead[maxn], esiz, n, m, N;
int cur[maxn], dep[maxn], gap[maxn];
int dis[maxn];
bool vis[maxn];
void init(void){
    memset(head, -1, sizeof(head));
    memset(fhead, -1, sizeof(fhead));
    esiz=0;
}

void addEdge(int from, int to, int dis){
    edges[esiz]=Edge(to, head[from], from, dis);
    head[from]=esiz++;
}

void addFEdge(int from, int to, int cap){
    edges[esiz]=Edge(to, fhead[from], from, cap);
    fhead[from]=esiz++;
    edges[esiz]=Edge(from, fhead[to], to, 0);
    fhead[to]=esiz++;
}

void Bellman(int s){
    queue<int> que;
    memset(vis, false, sizeof(vis));
    for (int i=0; i<=n; i++) dis[i]=INF;
    dis[s]=0; vis[s]=true;
    que.push(s);

    while (!que.empty()){
        int u=que.front(); que.pop();
        vis[u]=false;
        for (int i=head[u]; i!=-1; i=E.nxt){
            if (dis[E.to]<=dis[u]+E.cap) continue;
            dis[E.to]=dis[u]+E.cap;

            if (!vis[E.to]){
                vis[E.to]=true;
                que.push(E.to);
            }
        }
    }
}

void bfs(int t){
    queue<int> que;
    memset(dep, 0, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    memcpy(cur, fhead, sizeof(fhead));
    ++gap[dep[t]=1];
    que.push(t);

    while (!que.empty()){
        int u=que.front(); que.pop();
        for (int i=fhead[u]; i!=-1; i=E.nxt) if (!dep[E.to]){
            ++gap[dep[E.to]=dep[u]+1];
            que.push(E.to);
        }
    }
}

int dfs(int u, int dlt, int s, int t){
    if (u==t) return dlt;
    int flow=0;
    for (int &i=cur[u]; i!=-1; i=E.nxt) if (dep[E.to]==dep[u]-1){
        int res=dfs(E.to, min(dlt, E.cap-E.flow), s, t);
        flow+=res, dlt-=res;
        E.flow+=res, NE.flow-=res;
        if (!dlt) return flow;
    }
    if (!(--gap[dep[u]])) dep[s]=N+1;
    ++gap[++dep[u]];
    cur[u]=fhead[u];
    return flow;
}

int maxflow(int s, int t){
    bfs(t);
    int flow=0;
    while (dep[s]<=N) flow+=dfs(s, INF, s, t);
    return flow;
}

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        init();
        int a, b, ndis;
        scanf("%d%d", &n, &m);
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &a, &b, &ndis);
            addEdge(a, b, ndis);
        }

        int st, ed;
        scanf("%d%d", &st, &ed);
        Bellman(st);

        int siz=esiz;
        // esiz=0; Can't do this! 
        for (int i=0; i<siz; i++){
            if (dis[E.from]+E.cap==dis[E.to])
                addFEdge(E.from, E.to, 1);
        }

        N=n;
        int ans=maxflow(st, ed);
        printf("%d\n", ans);
    }

    return 0;
}
