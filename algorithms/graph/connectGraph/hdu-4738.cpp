#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e3+20, maxm=maxn*maxn*2;
struct Edge{
    int to, nxt, val;
    Edge(int to=0, int nxt=0, int val=0):
        to(to), nxt(nxt), val(val) {}
}edges[maxm];
int head[maxn], esize, n, m;
int dfn[maxn], low[maxn], tim;
int ans, cnt;
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to, int val){
    edges[esize]=Edge(to, head[from], val);
    head[from]=esize++;
}

void dfs(int u, int prev){
    dfn[u]=low[u]=++tim;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;
        if (i==(prev^1)) continue;
        if (!dfn[v]){
            dfs(v, i);
            low[u]=min(low[u], low[v]);
            // if (low[v]>=dfn[u]) iscut[u]=true;
            if (low[v]>dfn[u])
                if (ans==-1 || ans>edges[i].val) ans=edges[i].val;
        }else if (dfn[v]<dfn[u]) // && i!=(prev^1)) // antiEdge
            low[u]=min(low[u], dfn[v]);
    }
    // if (fa<0 && child==1) iscut[u]=false;
}

void getBCC(void){
    cnt=tim=0; ans=-1;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    for (int i=1; i<=n; i++)
        if (!dfn[i]) dfs(i, -1), cnt++;
}

int main(void){
    while (scanf("%d%d", &n, &m)==2 && n+m){
        init();
        int from, to, val;
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &from, &to, &val);
            addEdge(from, to, val);
            addEdge(to, from, val);
        }

        getBCC();
        if (ans==0) ans=1;
        if (cnt!=1) printf("0\n");
        else printf("%d\n", ans);
    }

    return 0;
}
