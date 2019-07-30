#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=600;
struct Node{
    int pre, rank;
}node[MAX+5];
struct Edge{
    int a, b;
    float val;
    bool operator < (const Edge &a) const{
        return val<a.val;
    }
}edge[MAX*MAX/2+5];
int n, m, px[MAX+5], py[MAX+5];
inline float dis(int a, int b){
    return (px[a]-px[b])*(px[a]-px[b])+(py[a]-py[b])*(py[a]-py[b]);
}

int find(int x){
    return (node[x].pre==x)?x:(node[x].pre=find(node[x].pre));
}

void join(int a, int b){
    a=find(a); b=find(b);
    if (a==b) return;
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank) node[b].pre=a;
    else node[a].pre=b;
}

void Kruskal(int size){
    for (int i=0, cnt=0; cnt<n-1 && i<size; i++){
        int &a=edge[i].a, &b=edge[i].b;
        if (find(a)==find(b)) continue;
        join(a, b); cnt++;
        printf("%d %d\n", a, b);
    }
}

int main(void){
    int size=0;
    scanf("%d", &n);
    for (int i=1; i<=n; i++){
        scanf("%d%d", &px[i], &py[i]);
        for (int j=1; j<i; j++){
            edge[size].a=i; edge[size].b=j;
            edge[size++].val=dis(i, j);
        }
    }
    scanf("%d", &m);
    for (int i=0; i<n; i++) {node[i].pre=i; node[i].rank=0;}    // 1
    for (int i=0, a, b; i<m; i++) {
        scanf("%d%d", &a, &b);
        join(a, b);
    }
    sort(edge, edge+size);                                  // 2
    Kruskal(size);

    return 0;
}
