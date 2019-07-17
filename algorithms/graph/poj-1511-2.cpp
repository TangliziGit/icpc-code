#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1e6, maxm=maxn;
const long long INF=1LL<<60;
struct Edge{
    int to, dis, next;
}edges[maxm+5], redges[maxn+5];
int size, rsize, head[maxn+5], rhead[maxn+5];

inline void addEdge(int from, int to, int dis){
    edges[size]=Edge{to, dis, head[from]};
    head[from]=size++;
    redges[rsize]=Edge{from, dis, rhead[to]};
    rhead[to]=rsize++;
}

long long dist[maxn+5];
long long Bellman(int n, int ahead[], Edge *aedges){
    int cnt[maxn+5]={0};
    bool inq[maxn+5]={false};
    queue<int> que;
    
    for (int i=0; i<=n; i++) dist[i]=INF; dist[1]=0;
    que.push(1);
    while (que.size()){
        int from=que.front(); que.pop();
        inq[from]=false;

        for (int i=ahead[from]; i!=-1; i=aedges[i].next){
            Edge &e=aedges[i];
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
    memset(head, -1, sizeof(head));
    memset(rhead, -1, sizeof(rhead));
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
            read(from); read(to); read(dis);
            addEdge(from, to, dis);
        }printf("%lld\n", Bellman(n, head, edges)+Bellman(n, rhead, redges));
    }
    
    return 0;
}
