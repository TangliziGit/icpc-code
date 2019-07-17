// POJ-1502
// to get the minumum distace with no negtive dis
//
// Description:
// 1. get vertex with minumum distance
// 2. do relax
//
// Details:
// 1. use priority_queue and pair<dis, verIdx>
// 2. use dis[verIdx] as marks if minumum (pair.dis=dis[pair.verIdx]?)
// 3. initialize edge, G, dis and que

#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> Node;                    // dis, VerIdx
const int VerMax=205, EdgeMax=VerMax*VerMax;
struct Edge{
    int from, to, dis;
    Edge(int from=0, int to=0, int dis=0):
        from(from),to(to),dis(dis) {}
};
vector<Edge> edge;
vector<int> G[VerMax+5];
int n, start[2], end[2], dist[VerMax+5];
int Dijkstra(int sIdx){
    int ans=0;
    priority_queue<Node, vector<Node>, greater<Node> > que;
    que.push(Node(0, sIdx));
    memset(dist, -1, sizeof(dist)); dist[sIdx]=0;
    while (que.size()){
        Node x=que.top(); que.pop();
        int dis=x.first, from=x.second;
        if (dis!=dist[from]) continue;
        if (ans<dis) ans=dis;
        for (int i=0; i<G[from].size(); i++){
            int &e=G[from][i], &to=edge[e].to;
            if (dist[to]!=-1 && dist[to]<=dis+edge[e].dis) continue;
            dist[to]=dis+edge[e].dis;
            que.push(Node(dist[to], to));
        }
    }return ans;
}

int main(void){
    char str[25];
    scanf("%d", &n);
    for (int i=2; i<=n; i++)
        for (int j=1; j<i; j++){
            scanf("%s", str);
            if (str[0]=='x') continue;
            edge.push_back(Edge(i, j, atoi(str)));
            G[i].push_back(edge.size()-1);
            edge.push_back(Edge(j, i, atoi(str)));
            G[j].push_back(edge.size()-1);
        }
    printf("%d\n", Dijkstra(1));

    return 0;
}
