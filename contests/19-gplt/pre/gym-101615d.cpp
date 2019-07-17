#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> Pair;
const int maxn=5e4+20, maxm=maxn;
struct Edge{
    int to, clr, next;
    Edge(int to, int clr, int next)
        :to(to), clr(clr), next(next) {}
    Edge(){}
}edges[maxm];
int head[maxm], siz;
int dfn[maxn], pre[maxn], pos[maxn], vis[maxn];
int n, m;

void init(){
    memset(head, -1, sizeof(head));
    siz=0;
}

void addEdge(int from, int to, int clr){
    edges[siz]=Edge(to, clr, head[from]);
    head[from]=siz++;
}

int tim=0;
void dfs(int x, int fa){
    pre[x]=tim; dfn[tim++]=x;
    for (int i=head[x]; i!=-1; i=edges[i].next) if (edges[i].to!=fa)
        dfs(edges[i].to, x);
    pos[x]=tim; dfn[tim++]=x;
}

void mark(int x, int y){
    if (pre[x]<pre[y])
        vis[pre[y]]+=1, vis[pos[y]+1]-=1;
    else
        vis[0]+=1, vis[pre[x]]-=1, vis[pos[x]+1]+=1;
}

void search(int from){
    vector<Pair> vec;
    for (int i=head[from]; i!=-1; i=edges[i].next){
        Edge &e=edges[i];
        vec.push_back(Pair(e.clr, e.to));
    }
    sort(vec.begin(), vec.end());

    int vsiz=vec.size(), ptr=0;
    for (int i=1; i<vsiz; i++) if (vec[i].first==vec[i-1].first){
        mark(from, vec[i].second);
        if (i==ptr+1) mark(from, vec[ptr].second);
    }else ptr=i;
}

int main(void){
    int from, to, clr;
    scanf("%d", &n);
    init();
    for (int i=0; i<n-1; i++){
        scanf("%d%d%d", &from, &to, &clr);
        addEdge(from, to, clr);
        addEdge(to, from, clr);
    }
    
    memset(dfn, 0, sizeof(dfn));
    memset(pre, 0, sizeof(pre));
    memset(pos, 0, sizeof(pos));
    memset(vis, 0, sizeof(vis));
    tim=0; dfs(1, -1);
    
    set<int> ans;
    for (int i=1; i<=n; i++) search(i);
    for (int i=1; i<2*n; i++){
        vis[i]+=vis[i-1];
        if (vis[i]==0) ans.insert(dfn[i]);
    }

    printf("%lu\n", ans.size());
    for (set<int>::iterator it=ans.begin(); it!=ans.end(); it++)
        printf("%d\n", *it);

    return 0;
}
