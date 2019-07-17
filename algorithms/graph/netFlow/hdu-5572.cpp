#define E (edges[i])
#define NE (edges[i^1])
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=(1<<10)+20, maxm=(maxn*10+maxn+10+200)*2;
const int INF=0x3f3f3f3f;
struct Edge{
    int to, nxt, cap, flow;
    Edge(int to=0, int nxt=-1, int cap=0, int flow=0):
        to(to), nxt(nxt), cap(cap), flow(flow) {}
}edges[maxm];
int head[maxn], esiz, N;
int cur[maxn], dep[maxn], gap[maxn];
int que[maxn], ql, qr;
void init(void){
    memset(head, -1, sizeof(head));
    esiz=0;
}

void addEdge(int from, int to, int cap){
    edges[esiz]=Edge(to, head[from], cap, 0);
    head[from]=esiz++;
    edges[esiz]=Edge(from, head[to], 0, 0);
    head[to]=esiz++;
}

void bfs(int t){
    // queue<int> que;
    memset(dep, 0, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    memcpy(cur, head, sizeof(head));
    ++gap[dep[t]=1];
    // que.push(t);
    que[ql=qr=1]=t;

    // while (!que.empty()){
    while (ql<=qr){
        // int u=que.front(); que.pop();
        int u=que[ql++];

        for (int i=head[u]; i!=-1; i=E.nxt) if (!dep[E.to]){
            ++gap[dep[E.to]=dep[u]+1];
            // que.push(E.to);
            que[++qr]=E.to;
        }
    }
}

int dfs(int u, int dlt, int s, int t){
    if (u==t) return dlt;
    int flow=0;
    for (int &i=cur[u]; i!=-1; i=E.nxt) if (dep[u]==dep[E.to]+1){
        int res=dfs(E.to, min(dlt, E.cap-E.flow), s, t);
        flow+=res, dlt-=res;
        E.flow+=res, NE.flow-=res;
        if (!dlt) return flow;
    }
    if (!(--gap[dep[u]])) dep[s]=N+1;
    ++gap[++dep[u]];
    cur[u]=head[u];
    return flow;
}

int maxflow(int s, int t){
    bfs(t);
    int flow=0;
    while (dep[s]<=N) flow+=dfs(s, INF, s, t);
    return flow;
}

int num[(1<<10)+20];
int main(void){
    int nn, nm, tmp, cap;
    while (scanf("%d%d", &nn, &nm)==2){
        init();
        memset(num, 0, sizeof(num));
        for (int i=0; i<nn; i++){
            int bin=0;
            for (int j=0; j<nm; j++){
                scanf("%d", &tmp);
                bin=bin*2+tmp;
            }
            num[bin]++;
        }

        int ed=(1<<nm);
        for (int i=0; i<ed; i++){
            addEdge(0, i+2, num[i]);
            for (int j=0; (1<<j)<=i; j++){
                if ((1<<j)&i) addEdge(i+2, ed+j+2, INF);
            }
        }

        for (int i=0; i<nm; i++){
            scanf("%d", &cap);
            addEdge(ed+i+2, 1, cap);
        }

        N=2+ed+nm;
        int ans=maxflow(0, 1);
        if (ans==nn) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
