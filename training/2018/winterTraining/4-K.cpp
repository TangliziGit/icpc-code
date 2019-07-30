#include <cstdio>
struct Node{
    int parent, rank;//, data;
}node[1000+5];
int find(int x){
    return (x==node[x].parent)?x:(node[x].parent=find(node[x].parent));
}

void join(int a, int b, int &n){
    a=find(a); b=find(b);
    if (a==b) return;

    n--;
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank) node[b].parent=a;
    else node[a].parent=b;
}

int main(void){
    int T, n, m;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        for (int i=0; i<n; i++) {node[i].rank=0; node[i].parent=i;}
        for (int i=0, tmp[2]; i<m; i++){
            scanf("%d%d", &tmp[0], &tmp[1]);
            join(tmp[0]-1, tmp[1]-1, n);
        }printf("%d\n", n);
    }

    return 0;
}
