#include <cstdio>
struct Node{
    int parent, rank, size;
    Node(int parent=0, int rank=0, int size=1):
        parent(parent), rank(rank), size(size) {}
}node[int(3e4)+5];
int find(int x){
    return (x==node[x].parent)?x:(node[x].parent=find(node[x].parent));
}

void join(int a, int b){
    a=find(a); b=find(b);
    if (a==b) return;
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank){
        node[b].parent=a;
        node[a].size+=node[b].size;
    }else{
        node[a].parent=b;
        node[b].size+=node[a].size;
    }
}

int main(void){
    int n, m;

    while (scanf("%d%d", &n, &m)==2 && n){
        for (int i=0; i<n; i++) node[i]=Node(i);
        for (int i=0, mm, tmp[2]; i<m; i++){
            scanf("%d%d", &mm, &tmp[0]);
            for (int j=0; j<mm-1; j++){
                scanf("%d", &tmp[1]);
                join(tmp[0], tmp[1]);
            }
        }printf("%d\n", node[find(0)].size);
    }

    return 0;
}
