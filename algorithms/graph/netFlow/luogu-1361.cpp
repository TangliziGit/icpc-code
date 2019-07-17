#define E (edges[i])
#define NE (edges[i^1])
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e4+20, maxm=5e6;
const int INF=0x3f3f3f3f;
struct Edge{
    int to, nxt, cap, flow;
    Edge(int to=0, int nxt=-1, int cap=0):
        to(to), nxt(nxt), cap(cap), flow(0) {}
}edges[maxm];
int head[maxn], esiz, n, m;
int cur[maxn], dep[maxn], gap[maxn], N;
int na[maxn], nb[maxn];
void init(void){
    memset(head, -1, sizeof(head));
    esiz=0;
}

void addEdge(int from, int to, int cap){
    edges[esiz]=Edge(to, head[from], cap);
    head[from]=esiz++;
    edges[esiz]=Edge(from, head[to], 0);
    head[to]=esiz++;
}

void bfs(int t){
    queue<int> que;
    memset(dep, 0, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    memcpy(cur, head, sizeof(head));
    ++gap[dep[t]=1];
    que.push(t);

    while (!que.empty()){
        int u=que.front(); que.pop();
        for (int i=head[u]; i!=-1; i=E.nxt) if (!dep[E.to]){
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
    cur[u]=head[u];
    return flow;
}

int isap(int s, int t){
    bfs(t);
    int flow=0;
    while (dep[s]<=N) flow+=dfs(s, INF, s, t);
    return flow;
}

int main(void){
    while (scanf("%d", &n)==1){
        init();
        int cap, tot=0;
        for (int i=0; i<n; i++) scanf("%d", &na[i]), tot+=na[i];
        for (int i=0; i<n; i++) scanf("%d", &nb[i]), tot+=nb[i];
        for (int i=0; i<n; i++){
            addEdge(0, i+2, na[i]);
            addEdge(i+2, 1, nb[i]);
        }
        N=2+n;

        int k, mid, capa, capb;
        scanf("%d", &m);
        while (m--){
            scanf("%d%d%d", &k, &capa, &capb);
            tot+=capa+capb;
            addEdge(0, N, cap);
            addEdge(N+1, 1, cap);
            for (int i=0; i<k; i++){
                scanf("%d", &mid); mid+=2;
                addEdge(N, mid, INF);
                addEdge(mid, N+1, INF);
            }
            N+=2;
        }
        printf("%d\n", tot-isap(0, 1));
    }

    return 0;
}
