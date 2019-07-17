#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> Node;                    // dis, VerIdx
const int VerMax=1020, EdgeMax=VerMax*VerMax, INF=0x3f3f3f3f;
int n, dist[VerMax+5], G[VerMax+5][VerMax+5];

struct cmp{
    bool operator ()(const Node &a, const Node &b){
        return a.first<b.first;
    }
};

int Dijkstra(int sIdx, int n){
    priority_queue<Node, vector<Node>, cmp> que;//greater<Node> > que;
    // !!!!! DON'T USE GREATER<NODE> !!!!!!!
    memset(dist, -1, sizeof(dist)); dist[sIdx]=INF;
    que.push(Node(INF, sIdx));

    while (!que.empty()){
        Node x=que.top(); que.pop();
        int dis=x.first, from=x.second;
        if (dis!=dist[from]) continue;
        
        for (int to=1; to<=n; to++) if (G[from][to]>0){
            int mincap=min(dis, G[from][to]);

            if (dist[to]!=-1 && dist[to]>=mincap) continue;
            dist[to]=mincap;
            que.push(Node(dist[to], to));
        }
    }return dist[n];
}

int main(void){
    int T, n, m, x, y, cap;

    scanf("%d", &T);

    for (int cnt=1; cnt<=T; cnt++){
        memset(G, -1, sizeof(G));
        scanf("%d%d", &n, &m);
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &x, &y, &cap);
            if (G[y][x]<cap) G[y][x]=G[x][y]=cap;
        }
        printf("Scenario #%d:\n%d\n\n", cnt, Dijkstra(1, n));
    }

    return 0;
}
