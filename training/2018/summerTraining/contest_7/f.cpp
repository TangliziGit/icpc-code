#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+20, maxm=5e5+20;
struct Edge{
    int from, to;
    Edge(int from=0, int to=0):
        from(from), to(to) {}
}edges[maxm*2];
int esize, pre[maxn], deg[maxn];
int val[maxn], n, m;

void addEdge(int from, int to){
    edges[esize++]=Edge(from, to);
}

int find(int x){
    return (x==pre[x])?(x):(pre[x]=find(pre[x]));
}

void join(int a, int b){
    a=find(a); b=find(b);
    if (a==b) return;
    pre[a]=b;
}

bool connect(void){
    for (int i=1; i<=n; i++) pre[i]=i;
    for (int i=0; i<esize; i++)
        join(edges[i].from, edges[i].to);

    int pres=find(1);
    for (int i=2; i<=n; i++)
        if (pres!=find(i)) return false;
    return true;
}

bool epath(bool &allEven){
    memset(deg, 0, sizeof(deg));
    for (int i=0; i<esize; i++){
        deg[edges[i].from]++;
        deg[edges[i].to]++;
    }

    int cnt=0;
    for (int i=1; i<=n; i++)
        if (deg[i]%2){
            cnt++;
            if (cnt>=3) return false;
        }
    if (cnt==1) return false;
    if (cnt==2) allEven=false;
    if (cnt==0) allEven=true;
    return true;
}

int getxor(int x, int cnt){
    if (cnt%2) return x;
    return 0;
}

int main(void){
    int T, a, b;

    scanf("%d", &T);
    while (T--){
        esize=0;
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++) scanf("%d", &val[i]);
        for (int i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            addEdge(a, b);
        }
    
        bool allEven;
        if (connect()==false) printf("Impossible\n");
        else if (epath(allEven)==false) printf("Impossible\n");
        else{
            int ans=0;
            if (!allEven){
                for (int i=1; i<=n; i++){
                    if (deg[i]%2) ans^=getxor(val[i], (deg[i]+1)/2);
                    else ans^=getxor(val[i], deg[i]/2);
                }
            }else{
                for (int i=1; i<=n; i++)
                    ans^=getxor(val[i], deg[i]/2);
                int tmp=ans;
                for (int i=1; i<=n; i++)
                    ans=max(ans, tmp^val[i]);
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
