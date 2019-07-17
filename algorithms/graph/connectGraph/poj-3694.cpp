#include <set>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+20, maxm=2e5+20;
// typedef pair<int, int> Pair;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=0):
        to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], n, esize, m;
int dfn[maxn], low[maxn], bccn[maxn], bcnt, tim;
int euler[maxn*2], pos[maxn], etim;
int rmq[maxn][maxn];
vector<int> bcc[maxn];
// stack<Pair> sta;
set<long long> bridges;
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from]);
    head[from]=esize++;
}

void addBridge(int from, int to){
    int u=min(from, to), v=max(from, to);
    bridges.insert(u+(long long)maxn*v);
}

void dfs(int u, int fa){
    low[u]=dfn[u]=++tim;
    euler[++etim]=u;
    if (pos[u]<0) pos[u]=etim;

    bool faPassed=false;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &to=edges[i].to;
        // search bridges
        if (!dfn[to]){
            // sta.push(Pair(u, to));
            dfs(to, u);
            euler[++etim]=u; // !
            low[u]=min(low[u], low[to]);
            // if (low[to]>=dfn[u]) // iscut
        }else if (dfn[to]<dfn[u]){
            if (to==fa && !faPassed) faPassed=true;
            else if ((to==fa && faPassed) || to!=fa){
                // sta.push(Pair(u, to));
                low[u]=min(low[u], dfn[to]);
            }
        }
        if (low[to]>dfn[u]) addBridge(u, to);
    }
}

void findBCC(void){
    bcnt=tim=etim;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(pos, -1, sizeof(pos));
    memset(bccn, 0, sizeof(bccn));
    for (int i=1; i<=n; i++)
        if (!dfn[i]) dfs(i, -1);
}

void ST(int n) {
    for (int i = 1; i <= n; i++)
        rmq[i][0] = euler[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int RMQ(int l, int r) {
    int k = 0;
    if (l>r) swap(l, r);
    while ((1 << (k + 1)) <= r - l + 1) k++;
    return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}

int main(void){
    while (scanf("%d%d", &n, &m)==2 && n+m){
        init();
        int to, from;
        for (int i=0; i<m; i++){
            scanf("%d%d", &to, &from);
            addEdge(to, from);
            addEdge(from, to);
        }

        findBCC();
        int q;
        scanf("%d", &q);
        while (q--){
            scanf("%d%d", &from, &to);
            // int lca=RMQ(pos[from], pos[to]);

            int st=min(pos[from], pos[to]), ed=max(pos[from], pos[to]);
            for (int i=st+1; i<ed; i++){
                int u=min(euler[i-1], euler[i]), v=max(euler[i-1], euler[i]);
                long long e=u+maxn*v;
                if (bridges.count(e)){bcnt--; bridges.erase(e);}
            }
        }
    }

    return 0;
}
