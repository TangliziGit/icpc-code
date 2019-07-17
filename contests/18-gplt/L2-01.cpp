#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> Node;
const int VerMax=505, INF=0x3f3f3f3f;
struct Edge{
    int from, to, dis;
    Edge(int from=0, int to=0, int dis=0):
        from(from), to(to), dis(dis) {}
};
int n, m, st, tar, pre[VerMax+5], val[VerMax+5], dis[VerMax+5];
vector<Edge> edge;
vector<int> G[VerMax+5];
void showpath(int idx, bool sign){
    if (idx!=0) showpath(pre[idx], false);
    printf("%d%c", idx, sign?'\n':' ');
}

void Dijkstra(int st, int tar){
    int stnum=0, num[VerMax+5];
    memset(dis, INF, sizeof(dis));
    memset(num, 0, sizeof(num));
    priority_queue<Node> que;
    que.push(Node(0, st)); dis[st]=0; num[st]=val[st];
    while (que.size()){
        Node x=que.top(); que.pop();
        int &from=x.second, &xdis=x.first;
        if (xdis!=dis[from]) continue;
        for (int i=0; i<G[from].size(); i++){
            Edge &e=edge[G[from][i]];
            int to=e.to;
            if (to==tar && dis[to]==dis[from]+e.dis) stnum++;
            else if (to==tar && dis[to]>dis[from]+e.dis) stnum=1;
            if (dis[to]<dis[from]+e.dis) continue;
            else if (dis[to]==dis[from]+e.dis && num[to]>=num[from]+val[to]) continue;
            dis[to]=dis[from]+e.dis;
            pre[to]=from; num[to]=num[from]+val[to];
            que.push(Node(dis[to], to));
        }
    }printf("%d %d\n", stnum, num[tar]);
    showpath(tar, true);
}

int main(void){
    scanf("%d%d%d%d", &n, &m, &st, &tar);
    for (int i=0; i<n; i++) scanf("%d", &val[i]);
    for (int i=0, x, y, tmp; i<m; i++){
        scanf("%d%d%d", &x, &y, &tmp);
        edge.push_back(Edge(x, y, tmp));
        G[x].push_back(edge.size()-1);
        edge.push_back(Edge(y, x, tmp));
        G[y].push_back(edge.size()-1);
    }Dijkstra(st, tar);

    return 0;
}
