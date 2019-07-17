#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=5e3+20, maxm=1e4+20;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=0):
        to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], esize, n, m;
int dfn[maxn], low[maxn], sccn[maxn], tim, scnt;
int deg[maxn];
stack<int> sta;
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from]);
    head[from]=esize++;
}

void dfs(int u, int prev){
    dfn[u]=low[u]=++tim;
    sta.push(u);
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;
        if (i==(prev^1)) continue;// if (v==fa) continue; // undirect graph -> direct
        if (!dfn[v]){
            dfs(v, i);
            low[u]=min(low[u], low[v]);
        }else if (!sccn[v])
            low[u]=min(low[u], dfn[v]);
    }
    if (low[u]==dfn[u]){
        scnt++;
        while (true){
            int x=sta.top(); sta.pop();
            sccn[x]=scnt;
            if (x==u) break;
        }
    }
}

void findSCC(void){
    scnt=tim=0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sccn, 0, sizeof(sccn));
    for (int i=1; i<=n; i++)
        if (!dfn[i]) dfs(i, -1);
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

        findSCC();
        memset(deg, 0, sizeof(deg));
        for (int u=1; u<=n; u++){
            for (int i=head[u]; i!=-1; i=edges[i].nxt){
                int &v=edges[i].to;
                if (sccn[u]!=sccn[v]) deg[sccn[u]]++; // , deg[sccn[v]]++;
            }
        }

        int ans=0;
        for (int i=1; i<=scnt; i++)
            if (deg[i]==1) ans++;
        printf("%d\n", (ans+1)/2);
    }

    return 0;
}
