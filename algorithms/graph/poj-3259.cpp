#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=500+20, INF=0x3f3f3f3f;
struct Edge{
    int from, to, dis;
};
vector<Edge> edges;
vector<int> G[maxn+5];
int dist[maxn+5];
void addEdge(int from, int to, int dis){
    edges.push_back((Edge){from, to, dis});
    G[from].push_back(edges.size()-1);
}

void init(void){
    for (int i=0; i<=maxn; i++) G[i].clear();
    edges.clear();
}

bool Bellman(int st, int n){
    int cnt[maxn+5]={0}, dist[maxn+5];
    bool inq[maxn+5]={false};
    queue<int> que;
    
    memset(dist, INF, sizeof(dist)); dist[st]=0;
    que.push(st);
    while (que.size()){
        int from=que.front(); que.pop();
        inq[from]=false;

        for (int i=0; i<G[from].size(); i++){
            Edge &e=edges[G[from][i]];
            int &to=e.to, &dis=e.dis;

            if (dist[to]<=dist[from]+dis) continue;
            dist[to]=dist[from]+dis;
            if (inq[to]) continue;
            inq[to]=true;

            que.push(to);
            if (++cnt[to]>n) return true;
        }
    }return false;
}

int main(void){
    int F, n, m, w, from, to, dis;

    scanf("%d", &F);
    while (F--){
        init();
        scanf("%d%d%d", &n, &m, &w);
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &from, &to, &dis);
            addEdge(from, to, dis);
            addEdge(to, from, dis);
        }
        for (int i=0; i<w; i++){
            scanf("%d%d%d", &from, &to, &dis);
            addEdge(from, to, -1*dis);
        }

        if (Bellman(1, n)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
