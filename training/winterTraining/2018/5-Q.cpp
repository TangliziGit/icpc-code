#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=100;
struct Edge{
    int x, y, dis;
    bool operator < (const Edge &a) const {
        return dis<a.dis;
    }
}edge[MAX*MAX/2+5];
struct Node{
    int parent, rank;
}node[MAX+5];
int n;
int find(int x){
    return (node[x].parent==x)?x:(node[x].parent=find(node[x].parent));
}

void join(int a, int b){
    if (node[a].rank==node[b].rank) node[a].rank++;
    if (node[a].rank>node[b].rank) node[b].parent=a;
    else node[a].parent=b;
}

int kruskal(int size){
    int sum=0;
    for (int i=0; i<n; i++) {node[i].parent=i; node[i].rank=0;}
    for (int i=0, cnt=0; cnt<n-1 && i<size; i++){
        int &x=edge[i].x, &y=edge[i].y, &dis=edge[i].dis;
        if (find(x)==find(y)) continue;
        join(x, y); sum+=dis; cnt++;
    }return sum;
}

int main(void){
    while (scanf("%d", &n)==1){
        int size=0;
        for (int i=0; i<n; i++)
            for (int j=0, tmp; j<n; j++){
                scanf("%d", &tmp);
                // if (i<=j) continue;
                edge[size].x=i; edge[size].y=j;
                edge[size++].dis=tmp;
            }
        sort(edge, edge+size);
        printf("%d\n", kruskal(size));
    }

    return 0;
}
