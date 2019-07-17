#include <functional>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int, int> Node;    // (dist, id)
const int maxn=1000;
struct Edge{
    int from, to, val;
    Edge(int from=0, int to=0, int val=0):
        from(from), to(to), val(val) {}
};
vector<Edge> edges;
vector<int> G[maxn+5];
int vis[maxn+5][maxn+5];
long long dist[maxn+5];

void addEdge(int from, int to, int val){
    if (vis[from][to]!=-1 && vis[from][to]<=val) return;
    edges.push_back(Edge(from, to, val));
    G[from].push_back(edges.size()-1);
    G[to].push_back(edges.size()-1);
    vis[from][to]=vis[to][from]=val;
}

long long dij(int tar){
    memset(dist, INF, sizeof(dist)); dist[1]=0;
    priority_queue<Node, vector<Node>, greater<Node> > que;
    que.push(Node(0, 1));

    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int i=0; i<G[from].size(); i++){
            Edge &e=edges[G[from][i]];
            int to=(e.to==from)?e.from:e.to;

            if (dist[to]<=dist[from]+e.val) continue;
            dist[to]=dist[from]+e.val;
            que.push(Node(dist[to], to));
        }
    }return dist[tar];
}

int main(void){
    int V, E;
    int from, to, val;

    memset(vis, -1, sizeof(vis));
    scanf("%d%d", &E, &V);
    for (int i=0; i<E; i++){
        scanf("%d%d%d", &from, &to, &val);
        addEdge(from, to, val); // duplication!
    }
    printf("%lld\n", dij(V));

    return 0;
}
