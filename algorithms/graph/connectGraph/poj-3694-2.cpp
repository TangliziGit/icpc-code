#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+20, maxm=2e5+20;
struct Edge{
    int to, nxt;
    bool isbr;
    Edge(int to=0, int nxt=0, bool isbr=false):
        to(to), nxt(nxt), isbr(isbr) {}
}edges[maxm*2+maxn*2];
int nhead[maxn], head[maxn], esize, n, m;
int low[maxn], dfn[maxn], sccn[maxn], tim, scnt;
int sta[maxn], siz;
int euler[maxn], epos[maxn], father[maxn];
int st[maxn][maxn];
set<long long> bri;
void init(void){
    memset(head, -1, sizeof(head));
    memset(nhead, -1, sizeof(nhead));
    bri.clear();
    esize=0;
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from], false);
    head[from]=esize++;
}

void addNEdge(int from, int to){
    edges[esize]=Edge(to, nhead[from], true);
    nhead[from]=esize++;
}

void addBridge(int u, int v){
    if (u>v) swap(u, v);
    bri.insert(u+maxn*(long long)v);
}

void dfs(int u, int prev){
    dfn[u]=low[u]=++tim;
    sta[siz++]=u;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;
        if (i==(prev^1)) continue;
        if (!dfn[v]){
            dfs(v, i);
            low[u]=min(low[u], low[v]);
        }else if (!sccn[v])
            low[u]=min(low[u], dfn[v]);
    }

    if (low[u]==dfn[u]){
        scnt++;
        while (true){
            int x=sta[--siz];
            sccn[x]=scnt;
            if (x==u) break;
        }
    }
}

void getSCC(void){
    scnt=tim=0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(sccn, 0, sizeof(sccn));
    for (int i=1; i<=n; i++)
        if (!dfn[i]) dfs(i, -1);
}

void dfsEuler(int u, int fa){
    euler[++tim]=u;
    father[u]=fa;
    if (epos[u]==-1) epos[u]=tim;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;
        if (v==fa) continue;
        dfsEuler(v, u);
        euler[++tim]=u;
    }
}

void ST(int n, int A[]) {
    for (int i=1; i<=n; i++)
        st[i][0]=A[i];
    for (int j=1; (1<<j)<=n; j++)
        for (int i=1; i+(1<<j)-1<=n; i++)
            st[i][j]=max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}

int RMQ(int l, int r) {
    int k=0;
    if (l>r) swap(l, r);
    while ((1<<(k+1)) <= r-l+1) k++;
    return max(st[l][k], st[r-(1<<k)+1][k]);
}

int main(void){
    while (scanf("%d%d", &n, &m)==2 && n+m){
        init();
        int a, b;
        for (int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            addEdge(a, b);
            addEdge(b, a);
        }

        getSCC();
        for (int u=1; u<=n; u++){
            for (int i=head[u]; i!=-1; i=edges[i].nxt){
                int &v=edges[i].to;
                if (sccn[u]!=sccn[v]){
                    addNEdge(sccn[u], sccn[v]);
                    addNEdge(sccn[v], sccn[u]);
                    addBridge(sccn[u], sccn[v]);
                }
            }
        }

        tim=0;
        memset(epos, -1, sizeof(epos));
        dfsEuler(1, -1);
        ST(scnt, euler);
        int q;
        scanf("%d", &q);
        while (q--){
            scanf("%d%d", &a, &b);

            // int pre=min(epos[a], epos[b]), post=max(epos[a], epos[b]);
            int anc=RMQ(epos[a], epos[b]);
            for (int fa=father[epos[a]], now=epos[a]; fa!=anc && fa!=-1; now=fa, fa=father[fa])
                bri.erase(now+maxn*fa), bri.erase(fa+maxn*now);
            for (int fa=father[epos[b]], now=epos[b]; fa!=anc && fa!=-1; now=fa, fa=father[fa])
                bri.erase(now+maxn*fa), bri.erase(fa+maxn*now);
            printf("%lu\n", bri.size());
        }
    }

    return 0;
}
