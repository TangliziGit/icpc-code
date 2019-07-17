#define E (edges[i])
#define NE (edges[i^1])
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=(1<<10)+20;// , maxm=(maxn*10+maxn+10+200)*2;
const int INF=0x3f3f3f3f;
struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):
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
        for (int i=0;i<=n;i++) G[i].clear();
        edges.clear();
    }
    void addEdge(int from, int to, int cap){
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
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
            for(int i=0;i<G[x].size();i++){
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

int num[(1<<10)+20];
int main(void){
    int nn, nm, tmp, cap;
    while (scanf("%d%d", &nn, &nm)==2){
        memset(num, 0, sizeof(num));
        for (int i=0; i<nn; i++){
            int bin=0;
            for (int j=0; j<nm; j++){
                scanf("%d", &tmp);
                bin=bin*2+tmp;
            }
            num[bin]++;
        }

        int ed=(1<<nm);
        dinic.init(2+ed+nm);
        for (int i=0; i<ed; i++){
            dinic.addEdge(0, i+2, num[i]);
            for (int j=0; (1<<j)<=i; j++){
                if ((1<<j)&i) dinic.addEdge(i+2, ed+j+2, INF);
            }
        }

        for (int i=0; i<nm; i++){
            scanf("%d", &cap);
            dinic.addEdge(ed+i+2, 1, cap);
        }

        int ans=dinic.maxFlow(0, 1);
        if (ans==nn) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
