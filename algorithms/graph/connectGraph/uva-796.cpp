#include <set>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;
const int maxn=1e4, maxm=1e5;
typedef pair<int, int> Pair;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=0):
        to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], esize, n;
int pre[maxn], low[maxn], tim;
set<Pair> ans;

void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
    ans.clear();
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from]);
    head[from]=esize++;
}

void dfs(int u, int fa){
    pre[u]=low[u]=++tim;
    // int child=0;
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int &to=edges[i].to;
        if (!pre[to]){
            // child++;
            dfs(to, u);
            low[u]=min(low[u], low[to]);
            // if (low[to]<=pre[u]) iscut[u]=true;
        }else if (pre[to]<pre[u] && to!=fa)
            low[u]=min(low[u], pre[to]);
        if (low[to]>pre[u]) ans.insert(Pair(min(u, to), max(u, to)));
    }
    // if (fa<0 && child==1) iscut[u]=false;
}

void getBridge(void){
    tim=0;
    memset(pre, 0, sizeof(pre));
    memset(low, 0, sizeof(low));
    for (int i=0; i<n; i++)
        if (!pre[i]) dfs(i, -1);
}

char line[500];
int main(void){
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
                ssin >> to; // scanf("%d", &to);
                addEdge(from, to);
            }
        }

        getBridge();
        printf("%lu critical links\n", ans.size());
        for (set<Pair>::iterator it=ans.begin(); it!=ans.end(); it++)
            printf("%d - %d\n", it->first, it->second);
        printf("\n");
    }

    return 0;
}
