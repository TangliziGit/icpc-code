#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn=100+5, INF=0x3f3f3f3f;
const double eps=10e-6, NINF=-1*(double)INF;
struct Edge{
    int from, to;
    double rate, com;
};
vector<Edge> edges;
vector<int> G[maxn+5];
void addEdge(const Edge e1, const Edge e2){
    edges.push_back(e1);
    G[e1.from].push_back(edges.size()-1);
    edges.push_back(e2);
    G[e2.from].push_back(edges.size()-1);
}

bool equal(const double &a, const double &b){
    return ((a-b<=eps) && (b-a<=eps));
}

bool Bellman(int st, double money, int n){
    int cnt[maxn+5]={0};
    double dist[maxn+5];
    bool inq[maxn+5]={0};
    queue<int> que;

    for (int i=0; i<=maxn; i++) dist[i]=NINF;
    inq[st]=true; dist[st]=money;
    que.push(st);
    while (que.size()){
        int from=que.front(); que.pop();
        inq[from]=false;

        for (int i=0; i<G[from].size(); i++){
            Edge &e=edges[G[from][i]];
            int &to=e.to;
            double mon=(dist[from]-e.com)*e.rate;

            if (dist[to]>mon || equal(dist[to], mon)) continue;
            if (to==st) return true;
            dist[to]=mon;

            if (inq[to]) continue;
            que.push(to); inq[to]=true;
            if (++cnt[to]>n) return true;
        }
    }
    return false;
}

int main(void){
    int n, m, st, from, to;
    double rate[2], com[2], money;

    scanf("%d%d%d%lf", &n, &m, &st, &money);
    for (int i=0; i<m; i++){
        scanf("%d%d%lf%lf%lf%lf", &from, &to, &rate[0], &com[0], &rate[1], &com[1]);
        addEdge((Edge){from, to, rate[0], com[0]}, (Edge){to, from, rate[1], com[1]});
    }
    if (Bellman(st, money, n)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
