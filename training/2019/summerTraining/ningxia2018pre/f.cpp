#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=0x3f3f3f3f;
const int maxn=200+200+20;

struct Edge{
    int from, to; LL cap, flow;
    Edge(int u, int v, LL c, LL f):
        from(u), to(v), cap(c), flow(f) {}
};

struct Dinic{
    int n, m, s, t;
    vector<int> G[maxn];
    vector<Edge> edges;
    bool vis[maxn];
    int dep[maxn], cur[maxn];

    void init(int n){
        this->n=n;
        for (int i=0; i<=n; i++) G[i].clear();
        edges.clear();
    }

    void addEdge(int from, int to, LL cap){
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool bfs(void){
        memset(vis, false, sizeof(vis));
        queue<int> Q;
        vis[s]=true; dep[s]=0;
        Q.push(s);

        while (!Q.empty()){
            int x=Q.front(); Q.pop();

            for (int i=0; i<G[x].size(); i++){
                Edge &e=edges[G[x][i]];
                if (!vis[e.to] && e.cap>e.flow){
                    vis[e.to]=true;
                    dep[e.to]=dep[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    LL dfs(int x, LL a){
        if (x==t || a==0) return a;
        LL flow=0, f;
        for (int &i=cur[x]; i<G[x].size(); i++){
            Edge &e=edges[G[x][i]];
            if (dep[e.to]==dep[x]+1 && (f=dfs(e.to, min(a, e.cap-e.flow)))>0){
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if (a==0) break;
            }
        }
        return flow;
    }

    LL maxFlow(int s, int t){
        this->s=s; this->t=t;
        LL flow=0;
        while (bfs()){
            memset(cur, 0, sizeof(cur));
            flow+=dfs(s, INF);
        }return flow;
    }
}dinic;

int main(void){
    int T, n, m;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        dinic.init(n+m+2);

        int s=n+m, t=n+m+1, cnt=0;
        LL sum=0, siz;
        for (int i=0; i<n; i++){
            scanf("%lld", &siz);
            dinic.addEdge(s, cnt++, siz);
            sum+=siz;
        }
        for (int i=0; i<m; i++){
            scanf("%lld", &siz);
            dinic.addEdge(cnt++, t, siz);
        }

        for (int i=0; i<n; i++){
            int n1, n2, to;
            scanf("%d%d", &n1, &n2);
            while (n1--){
                scanf("%d", &to); to--;
                dinic.addEdge(i, to+n, INF);
            }
            while (n2--){
                scanf("%d", &to); to--;
                dinic.addEdge(i, to, INF);
            }
        }

        printf("%lld\n", sum-dinic.maxFlow(s, t));
    }

    return 0;
}
