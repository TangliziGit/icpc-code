// why runtime error?
// because parent can't be nagetive in find();
#include <cstdio>
#include <cmath>
const int MAX=int(1e3);
struct Node{
    int parent, rank;
    Node(int parent=-1, int rank=0):
        parent(parent),rank(rank) {}
}node[MAX+5];
int px[MAX+5], py[MAX+5], vec[MAX+5];
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

inline bool graph(int a, int b, int mdis){
    int dis=(px[a]-px[b])*(px[a]-px[b])+(py[a]-py[b])*(py[a]-py[b]);
    if (dis>mdis*mdis) return false;
    return true; 
}

int main(void){
    int n, dis, size=0, oper[2];
    char ch[5];

    scanf("%d%d", &n, &dis);
    for (int i=1; i<=n; i++) scanf("%d%d", &px[i], &py[i]);

    while (scanf("%s%d", ch, &oper[0])==2){
        if (ch[0]=='O' && node[oper[0]].rank==0){
            node[oper[0]]=Node(oper[0], 1);
            for (int i=0; i<size; i++)
                if (graph(oper[0], vec[i], (double)dis)) join(oper[0], vec[i]);
            vec[size++]=oper[0];
        }else if (ch[0]=='S'){
            scanf("%d", &oper[1]);
            if (node[oper[0]].parent<0 || node[oper[1]].parent<0) printf("FAIL\n");
            else if (find(oper[0])==find(oper[1])) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }


    return 0;
}

