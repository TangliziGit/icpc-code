#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn=500+20, maxm=maxn*maxn, INF=0x3f3f3f3f;;
typedef pair<int, int> Node;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;
    }
};
struct Edge{
    int val[2], to, next;
    Edge(){}
    Edge(int x, int y, int to, int next)
        :to(to), next(next){
            val[0]=x; val[1]=y;
        }
}edges[maxm];
int head[maxn], siz;
int dist[maxn], pre_dis[maxn], pre_time[maxn], sdist[maxn];
int n, m;

void init(void){
    memset(head, -1, sizeof(head));
    siz=0;
}

void addEdge(int from, int to, int x, int y){
    edges[siz]=Edge(x, y, to, head[from]);
    head[from]=siz++;
}

int dij_time(int sta, int end){
    priority_queue<Node, vector<Node>, Cmp> que;
    memset(dist, INF, sizeof(dist));
    memset(sdist, INF, sizeof(sdist));
    dist[sta]=0;
    sdist[sta]=0;
    que.push(Node(0, sta));

    while (!que.empty()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int from=x.second;
        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            if (dist[e.to]<dist[from]+e.val[1]) continue;
            if (dist[e.to]==dist[from]+e.val[1]
                    && sdist[e.to]<=sdist[from]+e.val[0])
                continue;

            dist[e.to]=dist[from]+e.val[1];
            sdist[e.to]=sdist[from]+e.val[0];
            pre_time[e.to]=from;
            que.push(Node(dist[e.to], e.to));
        }
    }return dist[end];
}

int dij_dist(int sta, int end){
    priority_queue<Node, vector<Node>, Cmp> que;
    memset(dist, INF, sizeof(dist));
    memset(sdist, INF, sizeof(sdist));
    dist[sta]=0;
    sdist[sta]=0;
    que.push(Node(0, sta));

    while (!que.empty()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int from=x.second;
        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            if (dist[e.to]<dist[from]+e.val[0]) continue;
            if (dist[e.to]==dist[from]+e.val[0]
                    && sdist[e.to]<=sdist[from]+1)
                continue;

            dist[e.to]=dist[from]+e.val[0];
            sdist[e.to]=sdist[from]+1;
            pre_dis[e.to]=from;
            que.push(Node(dist[e.to], e.to));
        }
    }return dist[end];
}

void path(int pre[], int x, int sta, int end){
    if (x==sta) printf(" %d =>", x);
    else{
        path(pre, pre[x], sta, end);
        if (x!=end) printf(" %d =>", x);
        else printf(" %d\n", end);
    }
}

bool same_path(int sta, int tar){
    int x=tar;
    while (x!=sta){
        if (pre_dis[x]!=pre_time[x]) return false;
        x=pre_dis[x];
    }
    return true;
}

int main(void){
    scanf("%d%d", &n, &m);
    init();

    int a, b, x, y, one;
    for (int i=0; i<m; i++){
        scanf("%d%d%d%d%d", &a, &b, &one, &x, &y);
        addEdge(a, b, x, y);
        if (one==0) addEdge(b, a, x, y);
    }

    scanf("%d%d", &a, &b);
    int time=dij_time(a, b), dis=dij_dist(a, b);
    if (same_path(a, b)){
        printf("Time = %d; Distance = %d:", time, dis);
        path(pre_time, b, a, b);
    }else{
        printf("Time = %d:", time);
        path(pre_time, b, a, b);
        printf("Distance = %d:", dis);
        path(pre_dis, b, a, b);
    }

    return 0;
}
