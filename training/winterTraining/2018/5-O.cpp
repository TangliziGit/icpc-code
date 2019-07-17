#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <functional>
using namespace std;
const int maxn=110, maxm=maxn*maxn/2;
typedef pair<int, int> Node;                            // (dis, idx)
struct Edge{
    int a, b, dis;
    Edge(int a, int b, int dis)
        :a(a), b(b), dis(dis) {}
};
vector <int> E[maxn];           // 2 (int)
vector <Edge> edge;
int n, dis[maxn];
int Dijkstra(int start){
    int ans=0;
    memset(dis, -1, sizeof(dis)); dis[start]=0;
    priority_queue<Node, vector<Node>, greater<Node> > que; // 1
    que.push(Node(0, start));
    while (que.size()){
        Node x=que.top(); que.pop();
        int &from=x.second;
        // printf("%d dis-%d %d\n", from, x.first, dis[from]);
        if (x.first!=dis[from]) continue;               // !!!!!
        ans=max(ans, dis[from]);                        // 3
        // printf("%d dis-%d\n", from, dis[from]);
        for (int i=0; i<E[from].size(); i++){
            Edge &e=edge[E[from][i]];
            int to=(e.a==from)?e.b:e.a;
            // printf("%d %d %d\n", e.a, e.b, e.dis);
            if (dis[to]!=-1 && dis[to]<dis[from]+e.dis) continue;
            dis[to]=dis[from]+e.dis;
            que.push(Node(dis[to], to));
        }
    }return ans;
}

int main(void){
    char str[25];
    scanf("%d", &n);
    for (int i=2; i<=n; i++)                            // 4 (2, n)
        for (int j=1; j<i; j++){
            scanf("%s", str);
            if (str[0]=='x') continue;
            edge.push_back(Edge(i, j, atoi(str)));
            E[i].push_back(edge.size()-1); E[j].push_back(edge.size()-1); // 5 (.size)
        }
    printf("%d\n", Dijkstra(1));

    return 0;
}
