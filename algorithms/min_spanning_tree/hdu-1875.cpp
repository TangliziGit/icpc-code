#include <cmath>
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
    int from, to;
    double dis;
    Edge(int from=0, int to=0, double dis=0):
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

double Kruskal(int n){
    int cnt=0; double ans=0;
    sort(edges, edges+size);
    for (int i=0; i<=n; i++) nodes[i]=Node(i, 0);
    for (int i=0; i<size && cnt<n-1; i++){
        int &to=edges[i].to, &from=edges[i].from;
        double &dis=edges[i].dis;

        if (dis<10 || dis>1000) continue;
        if (find(from)==find(to)) continue;
        join(from, to); cnt++; ans+=dis;
    }return (cnt>=n-1)?(ans):(-1);
}

inline double distance(int x1, int y1, int x2, int y2){
    return sqrt((double)(x1-x2)*(x1-x2)+(double)(y1-y2)*(y1-y2));
}

int main(void){
    int T, from, to, dis, x[maxn+5], y[maxn+5];
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n); size=0;
        for (int i=1; i<=n; i++) scanf("%d%d", &x[i], &y[i]);
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            edges[size++]=Edge(i, j, distance(x[i], y[i], x[j], y[j]));

        double ans=Kruskal(n);
        if (ans<0) printf("oh!\n");
        else printf("%.1f\n", ans*100);
    }
    return 0;
}
