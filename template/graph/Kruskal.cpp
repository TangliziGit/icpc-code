// POJ-1258
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int VerMax=105, EdgeMax=VerMax*VerMax;
struct Edge{
    int from, to, dis;
    Edge(int from=0, int to=0, int dis=0):
        from(from), to(to), dis(dis) {}
    bool operator < (const Edge &a) const {
        return dis<a.dis;
    }
}edge[EdgeMax+5];
struct Node{
    int parent, rank;
    Node(int parent=0, int rank=0):
        parent(parent), rank(rank) {}
}node[VerMax+5];
int find(int x){
    return (x==node[x].parent)?x:(node[x].parent=find(node[x].parent));
}

void join(int a, int b){
    a=find(a); b=find(b);

    if (a==b) return;
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank) node[b].parent=a;
    else node[a].parent=b;
}

int Kruskal(const int &edgeSize, const int &verSize){
    int ans=0;
    for (int i=1; i<=verSize; i++) node[i]=Node(i, 0);
    sort(edge, edge+edgeSize);
    for (int i=0, cnt=0; cnt!=verSize && i<edgeSize; i++){
        Edge &e=edge[i];
        if (find(e.from)==find(e.to)) continue;
        join(e.from, e.to);
        cnt++; ans+=e.dis;
    }return ans;
}

int main(void){
    int n;

    while (scanf("%d", &n)==1){
        int size=0;
        for (int y=1; y<=n; y++)
            for (int x=1; x<=n; x++){
                scanf("%d", &edge[size].dis);
                if (y==x) continue;
                edge[size].from=y; edge[size++].to=x;
            }
        printf("%d\n", Kruskal(size, n));
    }

    return 0;
}
