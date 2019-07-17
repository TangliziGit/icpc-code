#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1010, maxm=maxn*maxn+10;
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
int n, m, size=0, price[maxn+5];

int find(int x){
    return (nodes[x].pre==x)?(x):(nodes[x].pre=find(nodes[x].pre));
}

void join(int a, int b){
    find(a); find(b);
    if (a==b) return;
    if (nodes[a].rank==nodes[b].rank) nodes[a].rank++;
    if (nodes[a].rank>nodes[b].rank) nodes[b].pre=a;
    else nodes[a].pre=b;
}

int Kruskal(void){
    int ans=0, cnt=0;
    sort(edges, edges+size);
    for (int i=0; i<size && cnt<n-1; i++){
        int &from=edges[i].from, &to=edges[i].to, &dis=edges[i].dis;

        if (find(from)==find(to)) continue;
        join(from, to); cnt++; ans+=dis;
    }return ans;
}

int main(void){
    int dis, T; size=0;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=0; i<=n; i++) nodes[i]=Node(i, 0);
        for (int i=1; i<=n; i++) scanf("%d", &price[i]);
        for (int from=1; from<=n; from++)
            for (int to=1; to<=n; to++){
                scanf("%d", &dis);
                edges[size++]=Edge(from, to, dis+price[from]+price[to]);
            }
        printf("%d\n", Kruskal());
    }
    
    return 0;
}
