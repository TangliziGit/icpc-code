#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=600;
struct Node{
    int pre, rank;
}node[MAX+5];
struct Edge{
    int a, b, val;
    bool operator < (const Edge &a) const{
        return val<a.val;
    }
}edge[MAX*MAX/2+5];
int n, T;
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

int Kruskal(int size){
    int ans=0;
    for (int i=0; i<n; i++) {node[i].pre=i; node[i].rank=0;}    // 1
    for (int i=0, cnt=0; cnt<n-1 && i<size; i++){
        int &a=edge[i].a, &b=edge[i].b, &val=edge[i].val;
        if (find(a)==find(b)) continue;
        join(a, b); cnt++; ans=max(ans, val);
    }return ans;
}

int main(void){
    scanf("%d", &T);
    while (T--){
        int size=0;
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            for (int j=0, tmp; j<n; j++){
                scanf("%d", &tmp);
                if (i<=j) continue;
                edge[size].a=i; edge[size].b=j;
                edge[size++].val=tmp;
            }
        sort(edge, edge+size);                                  // 2
        printf("%d\n", Kruskal(size));
    }

    return 0;
}
