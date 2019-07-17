#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=110, maxm=maxn*maxn, INF=0x3f3f3f3f;
typedef pair<long long, int> Node;
struct Edge{
    int to, next;
    long long cost;
    Edge(int to=0, int next=9, long long cost=0):
        to(to), next(next), cost(cost) {}
}edges[maxm+5];
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;
    }
};
struct Point{
    long long price;
    int level;
    Point(long long price=0, int level=0):
        price(price), level(level) {}
}points[maxn+5];
int head[maxn], esize, minlv[maxn+5], maxlv[maxn+5], n, m;
long long dist[maxn+5];
void addEdge(int from, int to, long long cost){
    edges[esize]=Edge(to, head[from], cost);
    head[from]=esize++;
}

void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

inline bool outer(const int &to, const int &from){
    if (abs(minlv[from]-points[to].level)<=m && abs(maxlv[from]-points[to].level)<=m)
        return false;
    return true;
}

long long Dij(void){
    priority_queue<Node, vector<Node>, Cmp> que;
    memset(dist, INF, sizeof(dist)); dist[1]=0;

    memset(maxlv, 0, sizeof(maxlv));
    memset(minlv, INF, sizeof(minlv));
    maxlv[1]=minlv[1]=points[1].level;

    que.push(Node(dist[1], 1));
    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to, &level=points[to].level;
            long long &dis=e.cost;

            if (outer(to, from) || dist[to]<=dist[from]+dis) continue;
            dist[to]=dist[from]+dis;
            maxlv[to]=max(maxlv[from], level);
            minlv[to]=min(minlv[from], level);
            
            que.push(Node(dist[to], to));
        }
    }

    long long ans=INF;
    for (int i=1; i<=n; i++)
        ans=min(dist[i]+points[i].price, ans);
    return ans;
}

int main(void){
    int price, level, x, to;
    long long cost;

    while (scanf("%d%d", &m, &n)==2 && n){
        init();
        for (int from=1; from<=n; from++){
            scanf("%lld%d%d", &points[from].price, &points[from].level, &x);
            for (int i=0; i<x; i++){
                scanf("%d%lld", &to, &cost);
                addEdge(from, to, cost);
            }
        }
        printf("%lld\n", Dij());
    }

    return 0;
}
