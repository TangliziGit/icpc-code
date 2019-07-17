#include <functional>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=1000, INF=0x3f3f3f3f;
typedef pair<int, int> Node;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first<b.first;
    }
};
struct Edge{
    int from, to, cap;
    Edge(int from=0, int to=0, int cap=0):
        from(from), to(to), cap(cap) {}
};
vector<Edge> edges;
vector<int> G[maxn+5];
int dist[maxn+5];

void addEdge(int from, int to, int cap){
    edges.push_back(Edge(from, to, cap));
    G[from].push_back(edges.size()-1);
    G[to].push_back(edges.size()-1);
}

int Dij(int tar){
    memset(dist, 0, sizeof(dist));
    priority_queue<Node, vector<Node>, Cmp> que; //greater<Node> > que;
    // DON'T USE GRAETER<ANYCLASS>  it's to slow !!!!!
    que.push(Node(INF, 1)); dist[1]=INF;

    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int i=0; i<G[from].size(); i++){
            Edge &e=edges[G[from][i]];
            int to=(e.to==from)?e.from:e.to;

            if (dist[to]>=min(dist[from], e.cap)) continue;
            dist[to]=min(dist[from], e.cap);
            que.push(Node(dist[to], to));
        }
    }return dist[tar];
}

void init(void){
    edges.clear();
    for (int i=0; i<=maxn; i++) G[i].clear();
}

int main(void){
    int T, n, E;

    scanf("%d", &T);
    for (int cnt=1; cnt<=T; cnt++){
        init();
        scanf("%d%d", &n, &E);
        for (int i=0; i<E; i++){
            int from, to, dis;
            scanf("%d%d%d", &from, &to, &dis);
            addEdge(from, to, dis);
        }
        printf("Scenario #%d:\n%d\n\n", cnt, Dij(n));
    }

    return 0;
}
