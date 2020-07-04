#include <queue>
#include <cstdio>
#include <utility>
#include <cstring>
using namespace std;
const int nmax = 1e3+10, mmax = 1e4+10, pmax = 1e2 + 10;
const int INF = 0x3f3f3f3f;
struct Node {
    int from, cap, cost;
    Node(int from, int cap, int cost):
        from(from), cap(cap), cost(cost) {}
};
struct Cmp {
    bool operator () (const Node &a, const Node &b) const {
        return a.cost > b.cost;
    }
};
struct Edge {
    int to, dis, next;
    Edge(int to, int dis, int next):
        to(to), dis(dis), next(next) {}
    Edge(){}
}edges[2*mmax];
int head[nmax], dis[nmax][pmax];
int n, m, esize, price[nmax];

void init(void) {
    memset(head, -1, sizeof(head));
    esize = 0;
}

void addEdge(int from, int to, int dis) {
    edges[esize] = Edge(to, dis, head[from]);
    head[from] = esize++;
}

int Dij(int start, int end, int cap) {
    priority_queue<Node, vector<Node>, Cmp> que;
    que.push(Node(start, 0, 0));

    for (int i=0; i<n; i++) 
        for (int p=0; p<=cap; p++) 
            dis[i][p] = INF;
    dis[start][0] = 0;

    while (que.size()) {
        Node n = que.top(); que.pop();
        // printf("from%d cap%d cost%d\n", n.from, n.cap, n.cost);
        if (dis[n.from][n.cap] != n.cost) continue;
        if (n.from == end) return n.cost;

        if (n.cap+1 <= cap && dis[n.from][n.cap+1] > n.cost + price[n.from]) {
            dis[n.from][n.cap+1] = n.cost + price[n.from];
            que.push(Node(n.from, n.cap+1, n.cost+price[n.from]));
        }

        for (int i=head[n.from]; i!=-1; i=edges[i].next) {
            Edge &e = edges[i];
            int rest = n.cap - e.dis;
            // printf("to%d dis%d next%d\n", e.to, e.dis, e.next);

            if (rest < 0) continue;
            if (dis[e.to][rest] < n.cost) continue;
            dis[e.to][rest] = n.cost;
            que.push(Node(e.to, rest, n.cost));
        }
    }

    return -1;
}

int main(void) {
    int from, to, dis, q, c;
    scanf("%d%d", &n, &m);

    init();
    for (int i=0; i<n; i++)
        scanf("%d", &price[i]);
    for (int i=0; i<m; i++) {
        scanf("%d%d%d", &from, &to, &dis);
        addEdge(from, to, dis);
        addEdge(to, from, dis);
    }

    scanf("%d", &q);
    while (q --> 0) {
        scanf("%d%d%d", &c, &from, &to);
        int ans = Dij(from, to, c);

        if (ans < 0) 
            printf("impossible\n");
        else printf("%d\n", ans);
    }

    return 0;
}
