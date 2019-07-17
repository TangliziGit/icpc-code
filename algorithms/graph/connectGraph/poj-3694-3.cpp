#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+20, maxm=200000*2+20;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=-1)
        :to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], esiz, n, m;
int low[maxn], dfn[maxn], sccn[maxn], fa[maxn], scnt, tim;
int bridgeCnt;
int pre[maxn];
stack<int> sta;

void init(void){
    memset(head, -1, sizeof(head));
    esiz=0;
}

void addEdge(int from, int to){
    edges[esiz]=Edge(to, head[from]);
    head[from]=esiz++;
}

int find(int x){
    return (x==pre[x])?x:(pre[x]=find(pre[x]));
}

void join(int u, int v){
    u=find(u); v=find(v);
    if (u==v) return;
    pre[u]=v;
}

void dfs(int u, int prev){
    fa[u]=prev;
    low[u]=dfn[u]=++tim;
    sta.push(u);

    bool fatherPassed=false;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;

        if (v==prev && fatherPassed==false){
            fatherPassed=true; continue;
        }
        if (!dfn[v]){
            dfs(v, u);
            low[u]=min(low[u], low[v]);
        }else if (!sccn[v])
            low[u]=min(low[u], dfn[v]);

        if (low[v]>dfn[u])
            bridgeCnt++;
    }

    if (low[u]==dfn[u]){
        scnt++;
        while (true){
            int x=sta.top(); sta.pop();
            sccn[x]=scnt;
            join(u, x);
            if (x==u) break;
        }
    }
}

void getBCC(void){
    bridgeCnt=scnt=tim=0;
    memset(low, 0, sizeof(low));
    memset(dfn, 0, sizeof(dfn));
    memset(sccn, 0, sizeof(sccn));
    for (int i=1; i<=n; i++) pre[i]=i;
    // for (int i=1; i<=n; i++) if (!dfn[i])
    dfs(1, 1); // attend this root!
}

void calc(int u, int v){
    if (dfn[u]>dfn[v]) swap(u, v);
    while (dfn[u]<dfn[v]){
        if (find(v)!=find(fa[v])){
            join(v, fa[v]);
            bridgeCnt--;
        }
        v=fa[v];
    }

    while (u!=v){
        if (find(u)!=find(fa[u])){
            join(u, fa[u]);
            bridgeCnt--;
        }
        u=fa[u];
    }
}

int main(void){
    int a, b, q, kase=0;
    while (scanf("%d%d", &n, &m)==2 && (n||m)){
        init();
        for (int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            addEdge(a, b);
            addEdge(b, a);
        }

        getBCC();
        scanf("%d", &q);
        printf("Case %d:\n", ++kase);
        while (q--){
            scanf("%d%d", &a, &b);
            if (find(a)!=find(b))
                calc(a, b);
            printf("%d\n", bridgeCnt);
        }
    }

    return 0;
}
