#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e6, maxm=1e4;
struct Node{
    int key, next;
    Node(int key=0, int next=-1):
        key(key), next(next) {}
}node[maxn+5];
int vis[maxm+5], del[(int)1e5+5];

int main(void){
    int head, n, dsize=0;

    scanf("%d%d", &head, &n);
    for (int i=0, addr=0; i<n; i++){
        scanf("%d", &addr);
        scanf("%d%d", &node[addr].key, &node[addr].next);
    }
    vis[abs(node[head].key)]=1;
    printf("%05d %d ", head, node[head].key);
    for (int u=head; u!=-1; u=node[u].next){
        int v=node[u].next;
        if (v==-1) break;
        if (vis[abs(node[v].key)]==0){
            vis[abs(node[v].key)]=1;
            printf("%05d\n%05d %d ", v, v, node[v].key);
            continue;
        }else del[dsize++]=v;
    }printf("-1\n");

    if (dsize){
        printf("%05d %d ", del[0], node[del[0]].key);
        for (int i=1; i<dsize; i++)
            printf("%05d\n%05d %d ", del[i], del[i], node[del[i]].key);
        printf("-1\n");
    }
    return 0;
}
