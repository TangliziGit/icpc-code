#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e5+20, maxm=1e6+20;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=0):
        to(to), nxt(nxt) {}
}edges[maxm*2];
int head[maxn], esize, n, m;
int low[maxn], dfn[maxn], sccn[maxn], scnt, tim;
int sta[maxn], siz;
int bridges[maxm][2], bsiz;
int maxlen;
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from]);
    head[from]=esize++;
}

void Tarjan(int u, int prev){
    low[u]=dfn[u]=++tim;
    sta[siz++]=u;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;
        if (i==(prev^1)) continue;
        if (!dfn[v]){
            Tarjan(v, i);
            low[u]=min(low[u], low[v]);
            if (low[v]>dfn[u]){
                bridges[bsiz][0]=u;
                bridges[bsiz++][1]=v;
            }
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
    bsiz=siz=scnt=tim=0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sccn, 0, sizeof(sccn));
    for (int i=1; i<=n; i++)
        if (!dfn[i]) Tarjan(i, -1);
}

int dp(int u, int fa){
    int mlen=0;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;
        if (v==fa) continue;
        int len=dp(v, u);
        maxlen=max(maxlen, mlen+len);
        mlen=max(mlen, len);
    }return mlen+1;
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
        init();
        for (int i=0; i<bsiz; i++){
            int u=bridges[i][0], v=bridges[i][1];
            addEdge(sccn[u], sccn[v]);
            addEdge(sccn[v], sccn[u]); // can be emit?
        }

        maxlen=0;
        dp(1, -1);
        printf("%d\n", scnt-1-maxlen);
    }

    return 0;
}
