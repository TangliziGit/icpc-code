#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100+20, maxm=(maxn+2)*(maxn+2)*2;
const int INF=5e5;
struct Edge{
    int to, nxt, cap, flow, cost;
    Edge(int to=0, int nxt=0, int cap=0, int flow=0, int cost=0):
        to(to), nxt(nxt), cap(cap), flow(flow), cost(cost) {}
}edges[maxm];
int head[maxn], esiz, n;
int pre[maxn], dis[maxn];
bool vis[maxn];
char map[maxn+20][maxn+20];
void init(void){
    memset(head, -1, sizeof(head));
    esiz=0;
}

void addEdge(int from, int to, int cap, int cost){
    edges[esiz]=Edge(to, head[from], cap, 0, cost);
    head[from]=esiz++;
    edges[esiz]=Edge(from, head[to], 0, 0, -cost);
    head[to]=esiz++;
}

bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0;i < n;i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1;i = edges[i].nxt)
        {
            int v = edges[i].to;
            if(edges[i].cap > edges[i].flow &&
               dis[v] > dis[u] + edges[i].cost )
            {
                dis[v] = dis[u] + edges[i].cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}
//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t];i != -1;i = pre[edges[i^1].to])
        {
            if(Min > edges[i].cap - edges[i].flow)
                Min = edges[i].cap - edges[i].flow;
        }
        for(int i = pre[t];i != -1;i = pre[edges[i^1].to])
        {
            edges[i].flow += Min;
            edges[i^1].flow -= Min;
            cost += edges[i].cost * Min;
        }
        flow += Min;
    }
    return flow;
}
// bool Bellman(int s, int t){
//     queue<int> que;
//     memset(vis, false, sizeof(vis));
//     memset(pre, -1, sizeof(pre));
//     for (int i=0; i<=n; i++) dis[i]=INF;
//     dis[s]=0; vis[s]=true;
//     que.push(s);
// 
//     while (!que.empty()){
//         int u=que.front(); que.pop();
// 
//         vis[u]=false;
//         for (int i=head[u]; i!=-1; i=edges[i].nxt){
//             Edge &e=edges[i];
//             int v=e.to;
//             if (e.cap<=e.flow || dis[v]<=dis[u]+e.cost) continue;
//             dis[v]=dis[u]+e.cost;
//             pre[v]=i;
// 
//             if (!vis[v]){
//                 vis[v]=true;
//                 que.push(v);
//             }
//         }
//     }
//     if (pre[t]==-1) return false;
//     return true;
// }
// 
// pair<int, int> minCost(int s, int t){
//     int flow=0, cost=0;
//     while (Bellman(s, t)){
//         int delta=INF;
//         for (int i=pre[t]; i!=-1; i=pre[edges[i^1].to])
//             delta=min(delta, edges[i].cap-edges[i].flow);
//         for (int i=pre[t]; i!=-1; i=pre[edges[i^1].to]){
//             edges[i].flow+=delta;
//             edges[i^1].flow-=delta;
//         }
//         cost+=dis[t]*delta;
//         flow+=delta;
//     }return make_pair(flow, cost);
// }

int main(void){
    int nx, ny, hx[maxn], hy[maxn], mx[maxn], my[maxn];
    
    while (scanf("%d%d", &ny, &nx)==2 && nx+ny){
        init();
        int hsiz=0, msiz=0;
        for (int y=0; y<ny; y++){
            scanf("%s", map[y]);
            for (int x=0; x<nx; x++){
                if (map[y][x]=='H') {hy[hsiz]=y, hx[hsiz]=x; hsiz++;}
                if (map[y][x]=='m') {my[msiz]=y, mx[msiz]=x; msiz++;}
            }
        }

        n=2+msiz+hsiz;
        for (int i=0; i<msiz; i++)
            for (int j=0; j<hsiz; j++){
                int u=i+2, v=j+msiz+2;
                addEdge(u, v, 1, abs(mx[i]-hx[j])+abs(my[i]-hy[j]));
            }
        for (int i=0; i<msiz; i++) addEdge(0, i+2, 1, 0);
        for (int i=0; i<hsiz; i++) addEdge(i+msiz+2, 1, 1, 0);

        int cost, ans=minCostMaxflow(0, 1, cost);
        printf("%d\n", cost);
    }

    return 0;
}
