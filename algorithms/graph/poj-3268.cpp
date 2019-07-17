#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1e3+20, INF=0x3f3f3f3f;
typedef pair<int, int> Node;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;     // choose bigger one
    }
};
struct Edge{
    int from, to, dis;
    Edge(int from=0, int to=0, int dis=0):
        from(from), to(to), dis(dis) {}
};
vector<Edge> edges;
vector<int> G[maxn+5], rG[maxn+5];
int ndis[maxn+5], rdis[maxn+5];
void addEdge(int from, int to, int dis){
    edges.push_back(Edge(from, to, dis));
    G[from].push_back(edges.size()-1);
    rG[to].push_back(edges.size()-1);
}

int Dij(int x, int n){
    memset(rdis, INF, sizeof(rdis)); rdis[x]=0;
    memset(ndis, INF, sizeof(ndis)); ndis[x]=0;
    priority_queue<Node, vector<Node>, Cmp> que;

    que.push(Node(ndis[x], x));
    while (!que.empty()){
        Node node=que.top(); que.pop();
        if (node.first!=ndis[node.second]) continue;

        int &from=node.second;
        for (int i=0; i<G[from].size(); i++){
            Edge &e=edges[G[from][i]];
            int &to=e.to, &dis=e.dis;

            if (ndis[to]<=ndis[from]+dis) continue;
            ndis[to]=ndis[from]+dis;
            que.push(Node(ndis[to], to));
        }
    }

    que.push(Node(rdis[x], x));
    while (!que.empty()){
        Node node=que.top(); que.pop();
        if (node.first!=rdis[node.second]) continue;

        int &from=node.second;
        for (int i=0; i<rG[from].size(); i++){
            Edge &e=edges[rG[from][i]];
            int &to=e.from, &dis=e.dis;

            if (rdis[to]<=rdis[from]+dis) continue;
            rdis[to]=rdis[from]+dis;
            que.push(Node(rdis[to], to));
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++)
        ans=max(ans, rdis[i]+ndis[i]);
    return ans;
}

void init(void){
    for (int i=0; i<=maxn; i++){
        G[i].clear();
        rG[i].clear();
    }edges.clear();
}

int main(void){
    int n, m, x, from, to, dis;

    init();
    scanf("%d%d%d", &n, &m, &x);
    for (int i=0; i<m; i++){
        scanf("%d%d%d", &from, &to, &dis);
        addEdge(from, to, dis);
    }printf("%d\n", Dij(x, n));

    return 0;
}
