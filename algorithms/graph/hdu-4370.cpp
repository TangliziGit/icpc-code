#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=320;
const long long INF=1LL<<60;
typedef pair<long long, int> Node;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;
    }
};
int G[maxn+5][maxn+5];

long long Dij(int n){
    long long dist[maxn+5], ans=0, circle1=INF, circle2=INF;
    priority_queue<Node, vector<Node>, Cmp> que;

    for (int i=0;i<=n; i++) dist[i]=INF;
    dist[1]=0;
    que.push(Node(dist[1], 1));
    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int to=1; to<=n; to++) if (to!=from){
            int &dis=G[from][to];

            if (to==1) circle1=min(circle1, dist[from]+dis);
            if (dist[to]<=dist[from]+(long long)dis) continue;
            dist[to]=dist[from]+(long long)dis;
            que.push(Node(dist[to], to));
        }
    }//return dist[n];

    ans=dist[n];
    for (int i=0;i<=n; i++) dist[i]=INF;
    dist[n]=0;
    que.push(Node(dist[n], n));
    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int to=1; to<=n; to++) if (to!=from){
            int &dis=G[from][to];

            if (to==n) circle2=min(circle2, dist[from]+dis);
            if (dist[to]<=dist[from]+(long long)dis) continue;
            dist[to]=dist[from]+(long long)dis;
            que.push(Node(dist[to], to));
        }
    }return min(ans, circle1+circle2);
}

int main(void){
    int n;

    while (scanf("%d", &n)==1 && n){
        for (int y=1; y<=n; y++)
            for (int x=1; x<=n; x++) scanf("%d", &G[y][x]);
        printf("%lld\n", Dij(n));
    }

    return 0;
}
