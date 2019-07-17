#include <cstdio>
const int MAX=50000;
struct Node{
    int parent, rank;
    Node(void):rank(0) {}
}node[MAX+5];
int find(int x){
    return (x==node[x].parent)?x:(node[x].parent=find(node[x].parent));
}

void join(int a, int b, int &n){
    a=find(a); b=find(b);
    if (a==b) return;
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank) node[b].parent=a;
    else node[a].parent=b;
    n--;
}

int main(void){
    int kcase=1, n, m;

    while (scanf("%d%d", &n, &m)==2 && n){
        for (int i=0; i<n; i++) node[i].parent=i;
        for (int i=0, tmp[2]; i<m; i++){
            scanf("%d%d", &tmp[0], &tmp[1]);
            join(tmp[0], tmp[1], n);
        }printf("Case %d: %d\n", kcase++, n);
    }

    return 0;
}
