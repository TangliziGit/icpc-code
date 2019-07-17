#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=500+20, maxm=maxn*(maxn-1);
struct Edge{
    int to, next;
    Edge(){}
    Edge(int to, int next)
        :to(to), next(next) {}
}edges[maxm];
int head[maxn], clr[maxn];
int siz;
int n, m, k;
bool vis[maxn];

void init(void){
    memset(head, -1, sizeof(head));
    siz=0;
}

void addEdge(int from, int to){
    edges[siz]=Edge(to, head[from]);
    head[from]=siz++;
}

bool dfs(int x){
    for (int i=head[x]; i!=-1; i=edges[i].next){
        Edge &e=edges[i];
        // printf("%d -> %d\n", x, e.to);
        if (vis[e.to]) continue;

        vis[e.to]=true;
        if (clr[e.to]==clr[x]) return true;
        if (dfs(e.to)==true)
            return true;
    }return false;
}

bool check(void){
    memset(vis, false, sizeof(vis));
    for (int i=0; i<n; i++) if (!vis[i]){
        if (dfs(i)) return false;
    }return true;
}

int main(void){
    scanf("%d%d%d", &n, &m, &k);

    init();
    int a, b;
    for (int i=0; i<m; i++){
        scanf("%d%d", &a, &b); a--; b--;
        addEdge(a, b);
        addEdge(b, a);
    }

    int nn;
    scanf("%d", &nn);
    while (nn--){
        bool ch[maxn]; int size=0;
        memset(ch, false, sizeof(ch));
        for (int i=0; i<n; i++){
            scanf("%d", &clr[i]);
            if (!ch[clr[i]]) size++;
            ch[clr[i]]=true;
        }
        if (size!=k || !check()) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}
