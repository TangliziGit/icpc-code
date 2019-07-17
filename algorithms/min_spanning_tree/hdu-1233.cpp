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
char sent[maxn][10];
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

int Kruskal(int n){
    int cnt=0, ans=0;
    sort(edges, edges+size);
    for (int i=0; i<=n; i++) nodes[i]=Node(i, 0);
    for (int i=0; i<size && cnt<n-1; i++){
        int &to=edges[i].to, &from=edges[i].from, &dis=edges[i].dis;

        if (find(from)==find(to)) continue;
        join(from, to); cnt++; ans+=dis;
    }return ans;
}

int main(void){
    int from, to, dis;
    while (scanf("%d", &n)==1 && n){
        size=0;
        for (int i=0; i<n*(n-1)/2; i++){
            scanf("%d%d%d", &from, &to, &dis);
            edges[size++]=Edge(from, to, dis);
        }printf("%d\n", Kruskal(n));
    }
    return 0;
}
