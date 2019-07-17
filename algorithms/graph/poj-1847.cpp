#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=105, maxm=maxn*maxn, INF=0x3f3f3f3f;
typedef pair<int, int> Node;
struct Edge{
    int to, dis, next;
    Edge(int to=0, int dis=0, int next=0):
        to(to), dis(dis), next(next) {}
}edges[maxm+5];
struct Cmp{
    bool operator () (const Node& a, const Node &b){
        return a.first>b.first;
    }
};
int dist[maxn+5], head[maxn+5], esize;
void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to, int dis){
    edges[esize]=Edge(to, dis, head[from]);
    head[from]=esize++;
}

int Dij(int st, int end){
    priority_queue<Node, vector<Node>, Cmp> que;
    memset(dist, INF, sizeof(dist)); dist[st]=0;

    que.push(Node(dist[st], st));
    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to, &dis=e.dis;

            if (dist[to]<=dist[from]+dis) continue;
            dist[to]=dist[from]+dis;

            que.push(Node(dist[to], to));
        }
    }return (dist[end]==INF)?-1:dist[end];
}

int main(void){
    int n, m, st, end, to;

    while (scanf("%d%d%d", &n, &st, &end)==3 && n){
        init();
        for (int from=1; from<=n; from++){
            scanf("%d", &m);
            for (int i=0; i<m; i++){
                scanf("%d", &to);
                addEdge(from, to, i);
            }
        }printf("%d\n", Dij(st, end));
    }

    return 0;
}
