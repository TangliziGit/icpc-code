#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=2e5+20, maxe=2*maxn;
set<int> uni;
struct Edge{
    int from, to, next;
    Edge(){}
    Edge(int from, int to, int next)
        :from(from), to(to), next(next) {}
}edges[maxe];
int siz, head[maxn];
int n, k;

void addEdge(int from, int to){
    edges[siz]=Edge(from, to, head[from]);
    head[from]=siz++;
}

void init(void){
    siz=0;
    memset(head, -1, sizeof(head));
}

long long ans=0;
int dfs(int x, int pre){
    int sum=uni.count(x);
    for (int i=head[x]; i!=-1; i=edges[i].next){
        Edge &e=edges[i];
        if (e.to==pre) continue;

        sum+=dfs(e.to, x);
    }
    ans+=min(sum, 2*k-sum);
    return sum; // min(sum, 2*k-sum);
}

int main(void){
    int tmp, from, to;
    scanf("%d%d", &n, &k);
    for (int i=0; i<k*2; i++){
        scanf("%d", &tmp);
        uni.insert(tmp);
    }

    init();
    for (int i=0; i<n-1; i++){
        scanf("%d%d", &from, &to);
        addEdge(from, to);
        addEdge(to, from);
    }

    ans=0;
    dfs(1, 0);
    printf("%I64d\n", ans);

    return 0;
}
