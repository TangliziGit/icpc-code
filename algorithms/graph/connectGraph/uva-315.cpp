#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
const int maxn=100+20, maxm=maxn*maxn*2;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=0):
        to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], n, esize;
int pre[maxn], low[maxn], tim;
bool iscut[maxn];

void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from]);
    head[from]=esize++;
}

int dfs(int u, int fa){
    int lowu, child=0;
    pre[u]=lowu= ++tim;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &to=edges[i].to;
        if (!pre[to]){
            child++;
            int lowto=dfs(to, u);
            lowu=min(lowu, lowto);
            if (lowto>=pre[u]) iscut[u]=true;
        }else if (pre[to]<pre[u] && to!=fa)
            lowu=min(lowu, pre[to]);
    }

    if (fa<0 && child==1) iscut[u]=false;
    low[u]=lowu;
    return lowu;
}

void findCut(void){
    tim=0;
    memset(pre, 0, sizeof(pre));
    memset(low, 0, sizeof(low));
    memset(iscut, false, sizeof(iscut));
    dfs(1, -1);
}

int main(void){
    char line[1000];
    while (scanf("%d", &n)==1 && n){
        init();
        int to, from;
        for (int i=1; i<=n; i++){
            scanf("%d", &from);
            fgets(line, sizeof(line), stdin);
            if (from==0) break;

            stringstream sin(line);
            while (sin >> to){
                addEdge(from, to);
                addEdge(to, from);
            }
        }

        findCut();
        int ans=0;
        for (int i=1; i<=n; i++)
            if (iscut[i]) ans++;
        printf("%d\n", ans);
    }

    return 0;
}
