#include <stack>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e3+20, maxm=2e6+20;
const long long INF=1LL<<60;
struct Edge{
    int to, dis, next;
    Edge(int to=0, int dis=0, int next=0):
        to(to), dis(dis), next(next) {}
}edges[maxm*2+5];
int head[maxn+5], size;

long long Bellman(int n){
    long long dist[maxn+5];
    int cnt[maxn+5]={0};
    bool inq[maxn+5]={false};
    stack<int> sta;// queue<int> que;

    for (int i=0; i<=n; i++) dist[i]=INF; dist[1]=0;
    inq[1]=true;
    sta.push(1);// que.push(1);
    while (sta.size()){
        int from=sta.top(); sta.pop();
        inq[from]=false;

        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to, &dis=e.dis;

            if (dist[to]<=dist[from]+(long long)dis) continue;
            dist[to]=dist[from]+(long long)dis;

            if (inq[to]) continue;
            sta.push(to);

            if (++cnt[to]>=n) return -1;
        }
    }

    if (dist[n]==INF) return -2;
    // for (int i=2; i<=n; i++)    // does it work?
    //     if (dist[i]<dist[i-1]) return -1;
    //  
    //  Obiviously not, we only need to find a way to the point n
    //  So there may be same points which value INF
    //  (But it surely values between i-1 and i+1)
    return dist[n];
}

void init(void){
    memset(head, -1, sizeof(head));
    size=0;
}

void addEdge(int from, int to, int dis){
    edges[size]=Edge(to, dis, head[from]);
    head[from]=size++;
}

int main(void){
    int n, ml, md;
    int from, to, dis;

    init();
    scanf("%d%d%d", &n, &ml, &md);
    for (int i=0; i<ml; i++){
        scanf("%d%d%d", &from, &to, &dis);
        if (from>to) swap(from, to);
        addEdge(from, to, dis);
    }
    for (int i=0; i<md; i++){
        scanf("%d%d%d", &from, &to, &dis);
        if (from<to) swap(from, to);
        addEdge(from, to, -dis);
    }
    printf("%lld\n", Bellman(n));

    return 0;
}
