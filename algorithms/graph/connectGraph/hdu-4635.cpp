#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+20, maxm=2*maxn;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=0):
        to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], esize;
long long n, m;
int dfn[maxn], low[maxn], sccn[maxn], tim, scnt;
long long ssize[maxn];
int sta[maxn], siz;
bool in[maxn], out[maxn];
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from]);
    head[from]=esize++;
}

void Tarjan(int u){
    low[u]=dfn[u]=++tim;
    sta[siz++]=u;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;
        if (!dfn[v]){
            Tarjan(v);
            low[u]=min(low[u], low[v]);
        }else if(!sccn[v])
            low[u]=min(low[u], dfn[v]);
    }

    if (low[u]==dfn[u]){
        scnt++;
        while (true){
            int x=sta[--siz];
            sccn[x]=scnt;
            ssize[scnt]++;
            if (x==u) break;
        }
    }
}

void getSCC(void){
    siz=scnt=tim=0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sccn, 0, sizeof(sccn));
    memset(ssize, 0, sizeof(ssize));
    for (int i=1; i<=n; i++)
        if (!dfn[i]) Tarjan(i);
}

int main(void){
    int T, kase=0;

    scanf("%d", &T);
    while (T--){
        scanf("%lld%lld", &n, &m);
        init();
        int from, to;
        for (int i=0; i<m; i++){
            scanf("%d%d", &from, &to);
            addEdge(from, to);
        }

        getSCC();
        if (scnt==1){
            printf("Case %d: -1\n", ++kase);
            continue;
        }

        memset(in, false, sizeof(in));
        memset(out, false, sizeof(out));
        for (int u=1; u<=n; u++){
            for (int i=head[u]; i!=-1; i=edges[i].nxt){
                int &v=edges[i].to;
                if (sccn[u]!=sccn[v]) out[sccn[u]]=true, in[sccn[v]]=true;
            }
        }

        long long msiz=maxn;
        for (int i=1; i<=scnt; i++)
            if ((!out[i]) || (!in[i]))
                msiz=min(msiz, ssize[i]);
        printf("Case %d: %lld\n", ++kase, n*(n-1)-(n-msiz)*msiz-m);
    }

    return 0;
}
