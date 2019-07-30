#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=1010;
struct Node{
    int pre, rank;
}node[MAX+5];
struct Edge{
    int a, b, val;
    bool operator < (const Edge &a) const{
        return val>a.val;
    }
}edge[MAX*MAX/2+5];
int n, m, T;
int find(int x){
    return (x==node[x].pre)?x:(node[x].pre=find(node[x].pre));
}

void join(int a, int b){
    a=find(a); b=find(b);
    if (a==b) return;
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank) node[b].pre=a;
    else node[a].pre=b;
}

int Kruskal(int size){
    int ans=0;
    for (int i=0; i<=n; i++) {node[i].pre=i; node[i].rank=0;}
    for (int i=0, cnt=0; cnt<n-1 && i<size; i++){
        if (find(1)==find(n)) return ans;
        int &a=edge[i].a, &b=edge[i].b, &val=edge[i].val;
        if (find(a)==find(b)) continue;
        join(a, b); cnt++; ans=val;
    }return ans;
}

int main(void){
    scanf("%d", &T);
    for (int kcase=1; kcase<=T; kcase++){
        int size=0;
        scanf("%d%d", &n, &m);
        for (; size<m; size++)
            scanf("%d%d%d", &edge[size].a, &edge[size].b, &edge[size].val);
        sort(edge, edge+size);
        printf("Scenario #%d:\n%d\n", kcase, Kruskal(size));
    }

    return 0;
}
