#include <stack>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=120, maxm=maxn*maxn*2;
struct Edge{
    int to, nxt;
    Edge(int to=0, int nxt=-1)
        :to(to), nxt(nxt) {}
}edges[maxm];
int head[maxn], esiz, n;
int low[maxn], dfn[maxn], sccn[maxn], tim, scnt;
int in[maxn], out[maxn];
stack<int> sta;

void init(void){
    memset(head, -1, sizeof(head));
    esiz=0;
}

void addEdge(int from, int to){
    edges[esiz]=Edge(to, head[from]);
    head[from]=esiz++;
}

void dfs(int u){
    // printf("Test %d\n", u);

    low[u]=dfn[u]=++tim;
    sta.push(u);
    for (int i=head[u]; i!=-1; i=edges[i].nxt){// if (i!=(prev^1)){
        int &v=edges[i].to;
        if (!dfn[v]){
            dfs(v);
            low[u]=min(low[u], low[v]);
        }else if (!sccn[v]) //?
            low[u]=min(low[u], dfn[v]);
    }

    if (low[u]==dfn[u]){
        scnt++;
        while (true){
            int x=sta.top(); sta.pop();
            sccn[x]=scnt;
            if (x==u) break;
        }
    }
}

void getSCC(void){
    scnt=tim=0;
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sccn, 0, sizeof(sccn));
    for (int u=1; u<=n; u++) if (!dfn[u])
        dfs(u);
}

int main(void){
    int to;

    while (scanf("%d", &n)==1){
        init();
        for (int i=1; i<=n; i++){
            while (scanf("%d", &to)==1 && to!=0)
                addEdge(i, to);
        }
        getSCC();
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));

        for (int u=1; u<=n; u++){
            for (int i=head[u]; i!=-1; i=edges[i].nxt){
                int &v=edges[i].to;

                if (sccn[u]!=sccn[v])
                    in[sccn[v]]++, out[sccn[u]]++;
            }
        }

        int inCnt=0, outCnt=0;
        for (int u=1; u<=scnt; u++){
            if (in[u]==0) inCnt++;
            if (out[u]==0) outCnt++;
        }

        int ans=(scnt==1)?0:(max(inCnt, outCnt));
        printf("%d\n%d\n", inCnt, ans);
    }

    return 0;
}
