#include <cstdio>
const int MAX=int(5e4);
struct Node{
    int parent, rank;
    Node(int parent=0, int rank=1):
        parent(parent),rank(rank) {}
}node[3*MAX+5];
int find(int x){
    return (x==node[x].parent)?x:(node[x].parent=find(node[x].parent));
}

void join(int a, int b){
    a=find(a); b=find(b);
    if (a==b) return;
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank) node[b].parent=a;
    else node[a].parent=b;
}

int main(void){
    int ans=0, n, m, oper[3];

    scanf("%d%d", &n, &m);
    for (int i=1; i<=3*n; i++) node[i]=Node(i);
    for (int snt=0; snt<m; snt++){
        scanf("%d%d%d", &oper[0], &oper[1], &oper[2]);
        if (oper[1]>n || oper[2]>n) {ans++; continue;}
        if (oper[0]==2 && oper[1]==oper[2]) {ans++; continue;}

        // self-0*n, eater-1*n, food-2*n
        if (oper[0]==1){
            // if (vis[oper[1]] && vis[oper[2]] && find(oper[1])!=find(oper[2])) {ans++; continue;}
            if (find(oper[1])==find(oper[2]+n) || find(oper[1])==find(oper[2]+2*n)){ans++; continue;}
            join(oper[1], oper[2]);
            join(oper[1]+n, oper[2]+n);
            join(oper[1]+2*n, oper[2]+2*n);
        }else if (oper[0]==2){
            if (find(oper[1])==find(oper[2]) || find(oper[1])==find(oper[2]+2*n)){ans++; continue;}
            join(oper[1], oper[2]+n);
            join(oper[1]+n, oper[2]+2*n);
            join(oper[1]+2*n, oper[2]);
        }
    }printf("%d\n", ans);

    return 0;
}
