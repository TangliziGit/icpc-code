// Dij卡常数了?
// 1. Bellman(optimed)  about 1500 ms
// 2. 零阶表            about 5500 ms
//
// TLE for reading data?

#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1e6, maxm=maxn;//, INF=0x3f3f3f3f;
const long long INF=1LL<<60;    // INF for long long
// typedef pair<long long, int> Node;
// struct Edge{
//     int from, to, dis;
// };
// struct Cmp{
//     bool operator () (const Node &a, const Node &b){
//         return a.first>b.first;
//     }
// };
// vector<Edge> edges;
// vector<int> G[maxn+5], rG[maxn+5];
// long long ndis[maxn+5], rdis[maxn+5];
struct Edge{
    int to, dis, next;
}edges[maxm+5], redges[maxn+5];
int size, rsize, head[maxn+5], rhead[maxn+5];

inline void addEdge(int from, int to, int dis){
    // edges.push_back(Edge{from, to, dis});
    // G[from].push_back(edges.size()-1);
    // rG[to].push_back(edges.size()-1);
    edges[size]=Edge{to, dis, head[from]};
    head[from]=size++;
    redges[rsize]=Edge{from, dis, rhead[to]};
    rhead[to]=rsize++;
}

// long long Dij(const int &n){
//     long long total=0;
//     priority_queue<Node, vector<Node>, Cmp> que;
//     for (int i=0; i<=n; i++) ndis[i]=INF; ndis[1]=0;
//     for (int i=0; i<=n; i++) rdis[i]=INF; rdis[1]=0;
// 
//     que.push(Node(ndis[1], 1));
//     while (!que.empty()){
//         Node x=que.top(); que.pop();
//         if (x.first!=ndis[x.second]) continue;
// 
//         int &from=x.second;
//         for (int i=0; i<G[from].size(); i++){
//             Edge &e=edges[G[from][i]];
//             int &to=e.to, &dis=e.dis;
// 
//             if (ndis[to]<=ndis[from]+dis) continue;
//             ndis[to]=ndis[from]+dis;
//             que.push(Node(ndis[to], to));
//         }
//     }
// 
//     que.push(Node(rdis[1], 1));
//     while (!que.empty()){
//         Node x=que.top(); que.pop();
//         if (x.first!=rdis[x.second]) continue;
// 
//         int &from=x.second;
//         for (int i=0; i<rG[from].size(); i++){
//             Edge &e=edges[rG[from][i]];
//             int &to=e.from, &dis=e.dis;
// 
//             if (rdis[to]<=rdis[from]+dis) continue;
//             rdis[to]=rdis[from]+dis;
//             que.push(Node(rdis[to], to));
//         }
//     }
// 
//     for (int i=1; i<=n; i++)
//         if (ndis[i]<INF && rdis[i]<INF) total+=ndis[i]+rdis[i]; // 1
//     return total;
// }

long long dist[maxn+5];
long long Bellman1(int n){
    int cnt[maxn+5]={0};
    bool inq[maxn+5]={false};
    queue<int> que;
    
    for (int i=0; i<=n; i++) dist[i]=INF; dist[1]=0;
    que.push(1);
    while (que.size()){
        int from=que.front(); que.pop();
        inq[from]=false;

        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to, &dis=e.dis;

            if (dist[to]<=dist[from]+dis) continue;
            dist[to]=dist[from]+dis;
            if (inq[to]) continue;
            inq[to]=true;

            que.push(to);
            // if (++cnt[to]>n) return -1;
        }
    }
    
    long long sum=0;
    for (int i=1; i<=n; i++) if (dist[i]<INF)
        sum+=dist[i];
    return sum;
}

long long Bellman2(int n){
    int cnt[maxn+5]={0};
    bool inq[maxn+5]={false};
    queue<int> que;
    
    for (int i=0; i<=n; i++) dist[i]=INF; dist[1]=0;
    que.push(1);
    while (que.size()){
        int from=que.front(); que.pop();
        inq[from]=false;

        for (int i=rhead[from]; i!=-1; i=redges[i].next){
            Edge &e=redges[i];
            int &to=e.to, &dis=e.dis;

            if (dist[to]<=dist[from]+dis) continue;
            dist[to]=dist[from]+dis;
            if (inq[to]) continue;
            inq[to]=true;

            que.push(to);
            // if (++cnt[to]>n) return -1;
        }
    }
    
    long long sum=0;
    for (int i=1; i<=n; i++) if (dist[i]<INF)
        sum+=dist[i];
    return sum;
}

void init(void){
    // for (int i=0; i<=maxn; i++){
    //     G[i].clear();
    //     rG[i].clear();
    // }edges.clear();
    // Edge n=Edge{0, 0, -1};
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
    // for (int i=0; i<=maxm; i++) edges[i]=n;
    // for (int i=0; i<=maxm; i++) redges[i]=n;
    rsize=size=0;
}

inline void read(int &num){
    char in;
    in=getchar();
    while(in <'0'|| in > '9') in=getchar();
    num = in -'0';
    while(in =getchar(),in >='0'&&in <='9')
        num *=10, num+=in-'0';
}

int main(void){
    int T, n, m, from, to, dis;

    scanf("%d", &T);
    while (T--){
        init();
        scanf("%d%d", &n, &m);
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &from, &to, &dis);
            // read(from); read(to); read(dis);
            addEdge(from, to, dis);
        }printf("%lld\n", Bellman1(n)+Bellman2(n));
        // printf("done");
    }
    
    return 0;
}
