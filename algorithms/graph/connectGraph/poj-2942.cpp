#include <vector>
#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e3+20, maxm=2e6+20;
typedef pair<int, int> Pair;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=-1)
        :to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], esiz, n, m;
int low[maxn], dfn[maxn], bccn[maxn], bcnt, tim;
bool graph[maxn][maxn], vis[maxn], odd[maxn];
int color[maxn];
vector<int> bcc[maxn];
stack<Pair> sta;

void init(void){
    memset(head, -1, sizeof(head));
    memset(graph, 0, sizeof(graph));
    esiz=0;
}

void addEdge(int from, int to){
    edges[esiz]=Edge(to, head[from]);
    head[from]=esiz++;
}

void dfs(int u, int fa){
    low[u]=dfn[u]=++tim;
    int child=0;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;

        if (!dfn[v]){
            sta.push(Pair(u ,v));
            child++;
            dfs(v, u);
            low[u]=min(low[u], low[v]);
            if (low[v]>=dfn[u]){
                bcnt++;
                bcc[bcnt].clear();
                while (true){
                    Pair e=sta.top(); sta.pop();
                    if (bccn[e.first]!=bcnt){
                        bcc[bcnt].push_back(e.first);
                        bccn[e.first]=bcnt;
                    }
                    if (bccn[e.second]!=bcnt){
                        bcc[bcnt].push_back(e.second);
                        bccn[e.second]=bcnt;
                    }

                    if (e.first==u && e.second==v) break;
                }
            }
        }else if (dfn[v]<dfn[u] && v!=fa){
            sta.push(Pair(u, v));
            low[u]=min(low[u], dfn[v]);
        }
    }
}

void getBCC(void){
    bcnt=tim=0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(bccn, 0, sizeof(bccn));
    for (int i=1; i<=n; i++) if (!dfn[i])
        dfs(i, -1);
}

bool bipart(int u, int status, int bccno){
    color[u]=status;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &v=edges[i].to;

        // cut point problem again.
        if (bccn[v]!=bccno) continue;
        if (color[v]==color[u]) return false;
        if (!color[v]){
            if (bipart(v, 3-color[u], bccno)==false)
                return false;
        }
    }return true;
}

int main(void){
    int a, b;
    while (scanf("%d%d", &n, &m)==2 && n){
        init();
        for (int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            graph[a][b]=true;
            graph[b][a]=true;
        }

        for (int i=1; i<=n; i++)
            for (int j=i+1; j<=n; j++)
                if (graph[i][j]==false){
                    addEdge(i, j);
                    addEdge(j, i);
                }

        getBCC();
        memset(odd, false, sizeof(odd));
        for (int u=1; u<=bcnt; u++){
            // Attend, the cut point can be duplicated.
            memset(color, 0, sizeof(color));
            for (int i=0; i<(int)bcc[u].size(); i++)
                bccn[bcc[u][i]]=u;

            if (!bipart(bcc[u][0], 1, u))
                for (int i=0; i<(int)bcc[u].size(); i++)
                    odd[bcc[u][i]]=true;
        }

        int ans=n;
        for (int i=1; i<=n; i++)
            ans-=odd[i];
        printf("%d\n", ans);
    }

    return 0;
}
