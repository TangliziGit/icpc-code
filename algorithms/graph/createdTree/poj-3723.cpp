#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e4+20, maxm=5e4+20;
struct Edge{
    int a, b, val;
    Edge(int a=0, int b=0, int val=0):
        a(a), b(b), val(val) {}
    bool operator < (const Edge &arg) const{
        return val<arg.val;
    }
}edges[maxm];
int pre[maxn], esize;
int n, m, r;
int find(int x){
    return (x==pre[x])?(x):(pre[x]=find(pre[x]));
}

long long Krus(void){
    long long cost=0;
    for (int i=0; i<=n+m; i++) pre[i]=i;
    for (int i=0; i<esize; i++){
        Edge &e=edges[i];

        int a=find(e.a), b=find(e.b);
        if (a==b) continue;
        pre[a]=b;
        cost+=(long long)e.val;
    }
    return cost+(n+m)*(long long)10000;
}

int main(void){
    int T, a, b, val;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &m, &r);
        esize=0;
        for (int i=0; i<r; i++){
            scanf("%d%d%d", &a, &b, &val);
            edges[esize++]=Edge(a, b+n, -1*val);
        }
        sort(edges, edges+esize);

        printf("%lld\n", Krus());
    }

    return 0;
}
