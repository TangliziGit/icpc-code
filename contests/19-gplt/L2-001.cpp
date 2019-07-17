#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> Node;
const int maxn=500+20, maxm=maxn*maxn*2;
const int INF=0x3f3f3f3f;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;
    }
};
struct Edge{
    int to, dis, next;
}edges[maxm];
int head[maxn], siz=0;
int dist[maxn], rnum[maxn], pnum[maxn], pre[maxn];
int n, m, start, tar;
int num[maxn];

void addEdge(int from, int to, int dis){
    edges[siz]=Edge{to, dis, head[from]};
    head[from]=siz++;
}

void init(void){
    memset(head, -1, sizeof(head));
    siz=0;
}

int dij(int sou, int tar){
    priority_queue<Node, vector<Node>, Cmp> que;

    memset(dist, INF, sizeof(dist));
    memset(rnum, 0, sizeof(rnum));
    memset(pnum, 0, sizeof(pnum));
    memset(pre, -1, sizeof(pre));
    dist[sou]=0; rnum[sou]=1; pnum[sou]=num[sou];
    pre[sou]=-1;
    que.push(Node(dist[sou], sou));
    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to, &dis=e.dis;

            if (dist[to]<dist[from]+dis) continue;
            if (dist[to]==dist[from]+dis){
                rnum[to]+=rnum[from];
                if (pnum[to]<pnum[from]+num[to]){
                    pnum[to]=pnum[from]+num[to];
                    pre[to]=from;
                }
            }else{
                rnum[to]=rnum[from];
                pnum[to]=pnum[from]+num[to];
                pre[to]=from;
            }

            dist[to]=dist[from]+dis;
            que.push(Node(dist[to], to));
        }
    }return dist[tar];
}

void path(int x, int isTar=false){
    if (x==-1) return;
    path(pre[x]);
    printf("%d%c", x, " \n"[isTar]);
}

int main(void){
    int from, to, dis;
    init();
    scanf("%d%d%d%d", &n, &m, &start, &tar);

    for (int i=0; i<n; i++) scanf("%d", &num[i]);
    for (int i=0; i<m; i++){
        scanf("%d%d%d", &from, &to, &dis);
        addEdge(from, to, dis);
        addEdge(to, from, dis);
    }

    // printf("%d\n", dij(start, tar));
    dij(start, tar);
    printf("%d %d\n", rnum[tar], pnum[tar]);
    path(tar, true);
    
    return 0;
}
