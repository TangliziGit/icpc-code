#include <map>
#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1e5+20, maxm=1e5+20, INF=0x3f3f3f3f;
typedef pair<int, int> Node;
struct Cmp{
    bool operator () (const Node &a, const Node &b){
        return a.first>b.first;
    }
};
struct Edge{
    int to, dis, next;
}edges[maxm+5];
int head[maxn+5], belong[maxn+5], size=0;
vector<int> layer[maxn+5];

void addEdge(int from, int to, int dis){
    edges[size]=Edge{to, dis, head[from]};
    head[from]=size++;
    edges[size]=Edge{from, dis, head[to]};
    head[to]=size++;
}

void init(void){
    memset(belong, -1, sizeof(belong));
    memset(head, -1, sizeof(head));
    size=0;
}

int Dij(int n, int step){
    int dist[maxn+5];
    priority_queue<Node, vector<Node>, Cmp> que;

    memset(dist, INF, sizeof(dist)); dist[1]=0;
    que.push(Node(dist[1], 1));
    while (que.size()){
        Node x=que.top(); que.pop();
        if (x.first!=dist[x.second]) continue;

        int &from=x.second;
        for (int i=head[from]; i!=-1; i=edges[i].next){
            Edge &e=edges[i];
            int &to=e.to, &dis=e.dis;

            if (dist[to]<=dist[from]+dis) continue;
            dist[to]=dist[from]+dis;
            que.push(Node(dist[to], to));
        }

        int &now=belong[from];
        for (int cnt=-1; cnt<=1; cnt+=2)
            if (now+cnt>=1 && now+cnt<=n) for (int i=0; i<layer[now+cnt].size(); i++){
                int &to=layer[now+cnt][i];

                if (dist[to]<=dist[from]+step) continue;
                dist[to]=dist[from]+step;
                que.push(Node(dist[to], to));
            }
    }return dist[n];
}

int main(void){
    int n, m, from, to, dis, T, lyr, step;

    scanf("%d", &T);
    for (int cnt=1; cnt<=T; cnt++){
        init();
        scanf("%d%d%d", &n, &m, &step);
        for (int i=1; i<=n; i++){
            scanf("%d", &lyr);
            layer[lyr].push_back(i);
            belong[i]=lyr;
        }
        for (int i=0; i<m; i++){
            scanf("%d%d%d", &from, &to, &dis);
            if (belong[from]-belong[to]==1 || belong[from]-belong[to]==-1)
                if (step>dis) addEdge(from, to, dis);
        }
        
        int ans=Dij(n, step);
        printf("Case #%d: ", cnt);
        if (ans==INF) printf("-1\n");
        else printf("%d\n", ans);
    }

    return 0;
}
