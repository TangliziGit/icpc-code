#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
const int maxn=200+20, maxm=maxn*(maxn+1);
const double INF=1LL<<50, eps=1e-6;
typedef pair<double, int> Node;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;
    }
};
struct Edge{
    int to, next;
    double dis;
}edges[maxm];
struct Point{
    int x, y;
}points[maxn];
int head[maxn], esize=0, psize=0;

inline bool equal(const double &a, const double &b){
    return ((a-b<=eps) && (b-a<=eps));
}

double Dij(void){
    double dist[maxn+5];
    priority_queue<Node, vector<Node>, Cmp> que;

    for (int i=0; i<=maxn; i++) dist[i]=INF;
    dist[psize-2]=0; que.push(Node(dist[psize-2], psize-2));
    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to;
            double mdis=dist[from]+e.dis;

            if (dist[to]<mdis || equal(dist[to], mdis)) continue;
            dist[to]=mdis;
            que.push(Node(dist[to], to));
        }
    }return dist[psize-1];
}

void addEdge(int from, int to, double dis){
    edges[esize]=Edge{to, head[from], dis};
    head[from]=esize++;
}

void init(void){
    memset(head, -1, sizeof(head));
    esize=0;
}

inline double distance(const Point &a, const Point &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(void){
    int x, y, lines[maxn+5], lsize=0;
    double dis;
    Point st, end;

    init();
    scanf("%d%d%d%d", &st.x, &st.y, &end.x, &end.y);
    while (scanf("%d%d", &x, &y)==2){
        lines[lsize++]=psize;
        points[psize++]=Point{x, y};
        while (scanf("%d%d", &x, &y)==2){
            if (x==-1) for (int i=0; i<lsize; i++){
                dis=distance(points[lines[i]], points[lines[lsize]]);
                addEdge(lines[i], lines[lsize], dis);
                addEdge(lines[lsize], lines[i], dis);
            }

            points[psize++]=Point{x, y};
            dis=distance(points[psize-1], points[psize-2]);
            addEdge(psize-2, psize-1, dis);
            addEdge(psize-1, psize-2, dis);
        }
    }
    points[psize++]=st;
    points[psize++]=end;
    for (int i=0; i<psize-2; i++){
        dis=distance(points[i], points[psize-1]);
        addEdge(i, psize-1, dis);
        addEdge(psize-1, i, dis);
        dis=distance(points[i], points[psize-2]);
        addEdge(i, psize-2, dis);
        addEdge(psize-2, i, dis);
    }
    printf("%f\n", Dij());

    return 0;
}
