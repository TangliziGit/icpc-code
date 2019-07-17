#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=120, maxm=maxn*maxn+10;
struct Node{
    int pre, rank;
    Node(int pre=0, int rank=0):
        pre(pre), rank(rank) {}
}nodes[maxn+5];
struct Edge{
    int from, to, dis;
    Edge(int from=0, int to=0, int dis=0):
        from(from), to(to), dis(dis) {}
    bool operator < (const Edge &a) const{
        return dis<a.dis;
    }
}edges[maxm+5];
int size, n;
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

int Kruskal(int shift){
    int cnt=0, ans=0;
    sort(edges, edges+size);
    for (int i=0; i<=n; i++) nodes[i]=Node(i, 0);
    for (int i=shift; i<size && cnt<n-1; i++){
        int &to=edges[i].to, &from=edges[i].from, &dis=edges[i].dis;

        if (find(from)==find(to)) continue;
        join(from, to); cnt++; ans+=dis;
    }return ans;
}

int main(void){
    int T, m, from, to, dis;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m); size=0;
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &from, &to, &dis);
            edges[size++]=Edge(from, to, dis);
        }
        
        int ans=Kruskal(0);
        if (Kruskal(1)==ans) printf("Not Unique!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
