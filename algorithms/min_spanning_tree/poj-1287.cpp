#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100, maxm=maxn*maxn;
struct Node{
    int pre, rank;
    Node(int pre=0, int rank=0):pre(pre), rank(rank) {}
}nodes[maxn+5];
struct Edge{
    int from, to, dis;
    Edge(int from=0, int to=0, int dis=0):
        from(from), to(to), dis(dis) {}
    bool operator < (const Edge &a) const{
        return dis<a.dis;
    }
}edges[maxm+5];
int n, m, esize;

int find(int x){
    return (nodes[x].pre==x)?(x):(nodes[x].pre=find(nodes[x].pre));
}

void join(int a, int b){
    a=find(a); b=find(b);
    if (a==b) return;
    if (nodes[a].rank==nodes[b].rank) nodes[a].rank++;
    if (nodes[a].rank>nodes[b].rank) nodes[b].pre=a;
    else nodes[a].pre=b;
}

int Kruskal(int n, int m){
    int cost=0;
    sort(edges, edges+m);
    for (int i=0, cnt=0; i<m && cnt<n-1; i++){
        int &from=edges[i].from, &to=edges[i].to;
        if (find(from)==find(to)) continue;
        join(from, to);
        cnt++; cost+=edges[i].dis;
    }return cost;
}

void init(int n){
    for (int i=0; i<=n; i++) nodes[i]=Node(i, 0);
    memset(edges, 0, sizeof(edges));
    n=esize=0;
}

int main(void){
    int dis, from, to;

    while (scanf("%d", &n)==1 && n){
        init(n);
        scanf("%d", &m);
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &from, &to, &dis);
            edges[esize++]=Edge(from, to, dis);
        }printf("%d\n", Kruskal(n, m));
    }

    return 0;
}
