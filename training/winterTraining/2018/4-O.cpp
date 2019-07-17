// too troublesome
#include <cstdio>
const int MAX=int(5e4);
struct Node{
    int parent, rank, sign;
    Node(int parent=0, int rank=1, int sign=-2):
        parent(parent),rank(rank),sign(sign) {}
}node[MAX+5];
int find(int x){
    return (x==node[x].parent)?x:(node[x].parent=find(node[x].parent));
}

void join(int a, int b){
    a=find(a); b=find(b);
    if (a==b) return;
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank) {node[b].parent=a; node[a].sign=node[b].sign;}
    else {node[a].parent=b; node[b].sign=node[a].sign;}
}

int main(void){
    int ans=0, n, k, kindSize=0, kind[3], oper[3];

    scanf("%d%d", &n, &k);
    for (int i=1; i<=n; i++) node[i]=Node(i);
    while (scanf("%d%d%d", &oper[0], &oper[1], &oper[2])==3 && oper[0]){
        if (oper[1]>n | oper[2]>n) {ans++; continue;}
        int a=find(oper[1]), b=find(oper[2]), ifpass=false;
        if (node[oper[1]].sign==-2 || node[oper[2]].sign==-2){
            node[oper[1]].sign=node[oper[2]].sign=-1; ifpass=true;
        }else if (node[a].sign==-1 || node[b].sign==-1) ifpass=true;

        if (oper[0]==1){
            if (ifpass==false && node[a].sign!=node[b].sign) {ans++; continue;} 
            join(oper[1], oper[2]);
        }else if (oper[0]==2){
            int &eater=a, &food=b, &fs=node[food].sign, &es=node[eater].sign;
            if ((ifpass==false && node[eater].sign!=(node[food].sign+1)%3) || oper[1]==oper[2]) {
            	ans++; continue;
            } 

            if (fs==-1){
                fs=kindSize++;
                if (kind[fs]==-1) kind[fs]=food;
            }
            if (es==-1) {
                es=(node[food].sign+1)%3;
                if (kind[es]==-1) kind[es]=eater;
                kindSize++;
            }
        }
    }printf("%d\n", ans);

    return 0;
}
