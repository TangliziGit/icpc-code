#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> Node;
const int maxn=3e4+20, maxm=1.5e5+20, INF=0x3f3f3f3f;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;
    }
};
struct Edge{
    int to, dis, next;
    Edge(int to, int dis, int next)
        :to(to), dis(dis), next(next) {}
    Edge(){}
}edges[maxm];
int head[maxn], siz;
int dist[maxn];
int n, m;

void init(){
    memset(head, -1, sizeof(head));
    siz=0;
}

void addEdge(int from, int to, int dis){
    edges[siz]=Edge(to, dis, head[from]);
    head[from]=siz++;
}

int dijkstra(int sou, int tar){
    priority_queue<Node, vector<Node>, Cmp> que;

    memset(dist, INF, sizeof(dist));
    dist[sou]=0;
    que.push(Node(0, sou));

    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int i=head[from]; i!=-1; i=edges[i].next){
            int &to=edges[i].to, &dis=edges[i].dis;
            if (dist[to]<=dist[from]+dis) continue;

            dist[to]=dist[from]+dis;
            que.push(Node(dist[to], to));
        }
    }return dist[tar];
}

int main(void){
    int from, to, dis;
    init();
    scanf("%d%d", &n, &m);

    for (int i=0; i<m; i++){
        scanf("%d%d%d", &from, &to, &dis);
        addEdge(from, to, dis);
    }printf("%d\n", dijkstra(1, n));

    return 0;
}
