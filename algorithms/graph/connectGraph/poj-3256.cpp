#include <cstdio>
#include <cstring>
const int maxn=1e3+20, maxm=1e4+20;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=0):
        to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], esize;
int st[maxn], k, n, m;
int pass[maxn];
bool vis[maxn];
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from]);
    head[from]=esize++;
}

void dfs(int x){
    vis[x]=true; pass[x]++;
    for (int i=head[x]; i!=-1; i=edges[i].nxt)
        if (!vis[edges[i].to]) dfs(edges[i].to);
}

int main(void){
    int from, to;
    while (scanf("%d%d%d", &k, &n, &m)==3){
        init();
        for (int i=0; i<k; i++) scanf("%d", &st[i]);
        for (int i=0; i<m; i++){
            scanf("%d%d", &from, &to);
            addEdge(from, to);
        }

        memset(pass, 0, sizeof(pass));
        for (int i=0; i<k; i++){
            memset(vis, false, sizeof(vis));
            dfs(st[i]);
        }

        int ans=0;
        for (int i=1; i<=n; i++)
            if (pass[i]==k) ans++;
        printf("%d\n", ans);
    }

    return 0;
}
