#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=100+20, maxm=maxn*maxn*2;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=0):
        to(to), nxt(nxt) {}
}edges[maxm];
int n, head[maxn], esize;
int pre[maxn], low[maxn], sccn[maxn], tim, scnt;
bool in[maxn], out[maxn];
stack<int> sta;

void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

void addEdge(int from, int to){
    edges[esize]=Edge(to, head[from]);
    head[from]=esize++;
}

void dfs(int u){
    pre[u]=low[u]= ++tim;
    sta.push(u);
    for (int i=head[u]; i!=-1; i=edges[i].nxt){
        int to=edges[i].to;
        // node `to` is in the same SCC.
        if (!pre[to]){
            dfs(to);
            low[u]=min(low[u], low[to]);
        }else if (!sccn[to]) 
            low[u]=min(low[u], pre[to]);
    }

    if (low[u]==pre[u]){ // u is the first point of this SCC.
        scnt++;
        while (sta.size()){
            int x=sta.top(); sta.pop();
            sccn[x]=scnt;
            if (x==u) break;
        }
    }
}

void findSCC(void){
    tim=scnt=0;
    while (sta.size()) sta.pop();
    memset(pre, 0, sizeof(pre));
    memset(low, 0, sizeof(low));
    memset(sccn, 0, sizeof(sccn));
    for (int i=1; i<=n; i++)
        if (!pre[i]) dfs(i);
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        init();
        int to;
        for (int i=1; i<=n; i++)
            while (true){
                scanf("%d", &to);
                if (to==0) break;
                addEdge(i, to);
            }

        findSCC();
        memset(in, false, sizeof(in));
        memset(out, false, sizeof(out));
        for (int u=1; u<=n; u++){
            for (int i=head[u]; i!=-1; i=edges[i].nxt){
                int &to=edges[i].to;
                if (sccn[u]!=sccn[to]) out[sccn[u]]=in[sccn[to]]=true;
            }
        }

        int incnt=0, outcnt=0;
        for (int i=1; i<=scnt; i++){
            if (!in[i]) incnt++;
            if (!out[i]) outcnt++;
        }

        int ans=((scnt==1)?0:max(incnt, outcnt));
        printf("%d\n%d\n", incnt, ans);
    }

    return 0;
}
