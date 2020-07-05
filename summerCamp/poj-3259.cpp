#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 5e2+10, maxm = 2*2700+10;
const int INF = 0x3f3f3f3f;
struct Edge {
    int to, dis, next;
    Edge(int to, int dis, int next):
        to(to), dis(dis), next(next) {}
    Edge() {}
}edges[maxm];
int head[maxn], esize;
int n, m;

void init(void) {
    memset(head, -1, sizeof(head));
    esize = 0;
}

void addEdge(int from, int to, int dis) {
    edges[esize] = Edge(to, dis, head[from]);
    head[from] = esize++;
}

bool bellman(int st, int n) {
    queue<int> que;
    bool inq[maxn] = {false};
    int cnt[maxn], dis[maxn];

    que.push(st);
    memset(cnt, 0, sizeof(cnt));
    memset(dis, INF, sizeof(dis));
    dis[st] = 0;

    while (que.size()) {
        int from = que.front(); que.pop();
        inq[from] = false;

        // printf("from%d\n", from);
        for (int i=head[from]; i!=-1; i=edges[i].next) {
            int &to=edges[i].to, &d=edges[i].dis;

            if (dis[to] <= dis[from] + d) continue;
            dis[to] = dis[from] + d;
            // printf("to%d dis%d\n", to, dis[to]);
            if (inq[to]) continue;
            inq[to] = true;
            if (++cnt[to] >= n) return true;
            que.push(to);
        }
    }

    return false;
}

int main(void) {
    int from, to, dis, w;
    scanf("%d", &n);
    while (scanf("%d%d%d", &n, &m, &w) == 3) {
        init();
        while (m --> 0) {
            scanf("%d%d%d", &from, &to, &dis);
            addEdge(from, to, dis);
            addEdge(to, from, dis);
        }

        while (w --> 0) {
            scanf("%d%d%d", &from, &to, &dis);
            addEdge(from, to, -dis);
        }

        if (!bellman(1, n)) printf("NO\n");
        else printf("YES\n");
    }

    return 0;
}
