#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=3e4+20, maxm=15e4+20, INF=0x3f3f3f3f;
typedef pair<int, int> Node;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;
    }
};
struct Edge{
    int to, dis, next;
}edges[maxm+5];
int head[maxn+5], size=0;

void addEdge(int from, int to, int dis){
    edges[size]=Edge{to, dis, head[from]};
    head[from]=size++;
}

void init(void){
    memset(head, -1, sizeof(head));
    size=0;
}

int Bellman(int n){
    int dist[maxn+5], sta[maxn+5], top=0;//cnt[maxn+5];
    bool inq[maxn+5]={false};
    // queue<int> que;

    memset(dist, INF, sizeof(dist)); dist[1]=0;
    sta[top++]=1;
    while (top!=0){
        int from=sta[--top];
        inq[from]=false;

        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to, &dis=e.dis;

            if (dist[to]<=dist[from]+dis) continue;
            dist[to]=dist[from]+dis;

            if (inq[to]) continue;
            sta[top++]=to; inq[to]=true;
        }
    }return dist[n];
}

int Dij(int n){
    int dist[maxn+5];
    priority_queue<Node, vector<Node>, Cmp> que;

    memset(dist, INF, sizeof(dist)); dist[1]=0;
    que.push(Node(dist[1], 1));
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
    }return dist[n];
}

int main(void){
    int n, m, from, to, dis;

    init();
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d%d%d", &from, &to, &dis);
        addEdge(from, to, dis);
    }printf("%d\n", Dij(n));//Bellman(n));

    return 0;
}
