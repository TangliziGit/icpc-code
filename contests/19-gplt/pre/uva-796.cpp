#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> Pair;
const int maxn=1e4+20, maxm=1e5+20;
struct Edge{
    int to, clr, next;
    Edge(int to, int clr, int next)
        :to(to), clr(clr), next(next) {}
    Edge(){}
}edges[maxm];
int head[maxn];
int pre[maxn], low[maxn];

void init(){
    memset(head, -1, sizeof(head));
    siz=0;
}

void addEdge(int from, int to, int clr){
    edges[siz]=Edge(to, clr, head[from]);
    head[from]=siz++;
}

void dfs(int x, int fa){
    pre[x]=low[x]=++tim;
    int child=0;
    for (int i=head[x]; i!=-1; i=edges[i].next){
        Edge &e=edges[i];
        if (!pre[e.to]){
            child++;
            dfs(e.to);
            low[x]=min(low[x], low[e.to]);
        }else if (pre[e.to]<pre[x] && fa!=x)
            low[x]=min(pre[e.to], low[x]);
        if (low[x]>pre[u])

    }
}

void findBridge(void){
    for (int i=0; i<n; i++) if (!pre[i])
        dfs(i);
}

int main(void){
    char line[maxlen];

    while (scanf("%d", &n)==1){
        fgets(line, sizeof(line), stdin);
        init();
        int from, to, cnt;
        for (int i=0; i<n; i++){
            fgets(line, sizeof(line), stdin);
            for (int i=0; line[i]; i++)
                if (line[i]=='(' || line[i]==')') line[i]=' ';
            stringstream ssin(line);

            ssin >> from >> cnt;
            for (int j=0; j<cnt; j++){
                ssin >> to;
                addEdge(from, to);
            }
        }
    
        
    }

    return 0;
}
