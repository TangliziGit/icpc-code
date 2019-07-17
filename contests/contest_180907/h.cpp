#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+20, maxm=2*maxn;
struct Edge{
    int to, nxt, dis;
    Edge(int to=0, int nxt=0, int dis=0):
        to(to), nxt(nxt), dis(dis) {}
}edges[maxm];
int head[maxn], esize;
int n;
long long f[maxn], g[maxn], ans[maxn], val[maxn];
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to, int dis){
    edges[esize]=Edge(to, head[from], dis);
    head[from]=esize++;
}

void dp(int u, int fa){
    if (ans[u]>=0) return;

    f[u]=g[u]=0;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &to=edges[i].to, &dis=edges[i].dis;
        if (to==fa) continue;

        dp(to, u);
        f[u]=max(f[to]+val[to]-val[u]-dis, f[u]);
        g[u]=max(g[to]+val[u]-val[to]-dis, g[u]);
    }
    ans[u]=f[u]+g[u];
}

int main(void){
    int T;
    int a, b, dis;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=1; i<=n; i++) scanf("%lld", &val[i]);

        init();
        for (int i=0; i<n-1; i++){
            scanf("%d%d%d", &a, &b, &dis);
            addEdge(a, b, dis); addEdge(b, a, dis);
        }

        memset(ans, -1, sizeof(ans));
        dp(1, -1);
        long long mans=0;
        for (int i=1; i<=n; i++) mans=max(ans[i], mans);
        printf("%lld\n", mans);
    }

    return 0;
}
