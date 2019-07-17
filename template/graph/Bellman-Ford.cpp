// POJ-1502
// to check negtive circle, if not return minumum distance
//
// Description:
// 1. do n-1 times relax for all edges (or check if dis[u]=dis[v]+dis[v, u])
//
// Details:
// 1. use queue to push and get the vertax
// 2. use cnt[verIdx] to count n-1 for each vertax
// 3. use inq[verIdx] to check if in queue(when process u, set inq[u] false)
// 4. despite of inq, do relax(but que.push)
// 5. initialize edge, G, dis and que

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int VerMax=205, INF=0x3f3f3f3f;
struct Edge{
    int from, to, dis;
    Edge(int from=0, int to=0, int dis=0):
        from(from),to(to),dis(dis) {}
};
vector<Edge> edge;
vector<int> G[VerMax];
int BellmanFord(int verSize){
    int ans=0, cnt[VerMax]={0}, dis[VerMax];
    bool inq[VerMax]={0};
    queue<int> que;
    que.push(1);
    memset(dis, INF, sizeof(dis));
    inq[1]=true; dis[1]=0;
    while (que.size()){
        int from=que.front(); que.pop();
        inq[from]=false; // ans=max(ans, dis[from]);
        for (int i=0; i<G[from].size(); i++){
            Edge &e=edge[G[from][i]]; int to=e.to;
            if (dis[to]<=dis[from]+e.dis) continue;
            dis[to]=dis[from]+e.dis;
            if (inq[to]) continue;
            que.push(to);
            // if (++cnt[to]>verSize) return 0;     // why n+1? code from purple book P363
            if (++cnt[to]>=verSize-1) return 0;
        }
    }
    for (int i=1; i<=verSize; i++) ans=max(ans, dis[i]);
    return ans;
}

int main(void){
    int n;
    char str[25];
    scanf("%d", &n);
    for (int y=2; y<=n; y++)
        for (int x=1; x<y; x++){
            scanf("%s", str);
            if (str[0]=='x') continue;
            edge.push_back(Edge(y, x, atoi(str)));
            G[y].push_back(edge.size()-1);
            edge.push_back(Edge(x, y, atoi(str)));
            G[x].push_back(edge.size()-1);
        }
    printf("%d\n", BellmanFord(n));

    return 0;
}
