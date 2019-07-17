// HDU-1532
// to get maximum flow from start to target
//
// Description:
// 1. get augmenting path until not exits
// 2. update the flow for each edge
//
// Details:
// 1. BFS to update aug[] and proir[] for each feasible vertax
// 2. attend to the meaning of aug and proir:
//      aug is the minimum residual(maximum feasible flow) for the path
//      proir is a edge for a vertax in the path
// 3. residual[u, v]+residual[v, u]==cap[u, v]
// 4. the antiparallel is temporacy, for flow[u, v]+flow[v, u]==0.
//      And we want to get the flow which positive
// 5. augmenting path is "additive and subtractive" for update flow

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int maxn=200, maxm=200, INF=0x3f3f3f3f;
struct Edge{
    int from, to, cap, flow;
    Edge(int from=0, int to=0, int cap=0, int flow=0):
        from(from), to(to), cap(cap), flow(flow) {}
};
vector<Edge> edge;
vector<int> G[maxn+5];
void addEdge(int from, int to, int cap){
    edge.push_back(Edge(from, to, cap, 0));
    G[from].push_back(edge.size()-1);
    edge.push_back(Edge(to, from, 0, 0));
    G[to].push_back(edge.size()-1);
}

int maxFlow(int st, int tar){
    int flow=0, proir[maxn]={0};
    while (1){
        int aug[maxn]={0};
        queue<int> que;
        que.push(st); aug[st]=INF;
        while (que.size()){
            int x=que.front(); que.pop();
            for (int i=0; i<G[x].size(); i++){
                Edge &e=edge[G[x][i]];
                if (!(aug[e.to]==0 && e.cap>e.flow)) continue;
                proir[e.to]=G[x][i];        // 1 G[x][i]
                aug[e.to]=min(aug[x], e.cap-e.flow);    // cap-flow means the residual
                que.push(e.to);
            }
            if (aug[tar]) break;
        }
        if (aug[tar]==0) break;             // augmenting path not exits
        for (int u=tar; u!=st; u=edge[proir[u]].from){
            edge[proir[u]].flow+=aug[tar];  // 2 tar
            edge[proir[u]^1].flow-=aug[tar];
        }flow+=aug[tar];
    }return flow;
}

int main(void){
    int n, m;

    while (scanf("%d%d", &m, &n)==2 && n){
        edge.clear();
        for (int i=0; i<n; i++) G[i].clear();
        for (int i=0, from, to, cap; i<m; i++){
            scanf("%d%d%d", &from, &to, &cap);
            addEdge(from, to, cap);
        }
        printf("%d\n", maxFlow(1, n));
    }

    return 0;
}
