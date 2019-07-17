#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=120, maxm=maxn*maxn+10, maxnn=50, INF=0x3f3f3f3f;
const int dir[4][2]={1, 0, 0, 1, -1, 0, 0, -1};
struct Point{
    int x, y;
    Point(int x=0, int y=0):
        x(x), y(y) {}
}points[maxn+5];
struct Node{
    int pre, rank;
    Node(int pre=0, int rank=0):
        pre(pre), rank(rank) {}
}nodes[maxn+5];
struct Edge{
    int from, to, dis;
    Edge(int from=0, int to=0, int dis=0):
        from(from), to(to), dis(dis) {}
    bool operator < (const Edge &a) const{
        return dis<a.dis;
    }
}edges[maxm+5];
int size, n, G[maxn+5][maxn+5], nx, ny;
int map[maxnn+5][maxnn+5];
int find(int x){
    return (nodes[x].pre==x)?(x):(nodes[x].pre=find(nodes[x].pre));
}

void join(int a, int b){
    a=find(a); b=find(b);
    if (a==b) return;
    if (nodes[a].rank==nodes[b].rank) nodes[a].rank++;
    if (nodes[a].rank>nodes[b].rank) nodes[b].pre=a;
    else nodes[a].pre=b;
}

int Kruskal(int n){
    int cnt=0, ans=0;
    sort(edges, edges+size);
    for (int i=0; i<=n; i++) nodes[i]=Node(i, 0);
    for (int i=0; i<size && cnt<n-1; i++){
        int &to=edges[i].to, &from=edges[i].from, &dis=edges[i].dis;

        if (find(from)==find(to)) continue;
        join(from, to); cnt++; ans+=dis;
    }return ans;
}

void bfs(int st){
    typedef pair<Point, int> Pair;
    bool vis[maxnn+5][maxnn+5]={false};
    queue<Pair> que;

    que.push(Pair(points[st], 0));
    vis[points[st].y][points[st].x]=true;
    while (que.size()){
        Pair from=que.front(); que.pop();

        for (int i=0; i<4; i++){
            int x=from.first.x+dir[i][0], y=from.first.y+dir[i][1];

            if (x>=nx || y>=ny || x<0 || y<0) continue;
            if (map[y][x]==-1 || vis[y][x]) continue;

            if (map[y][x]>0)
                G[st][map[y][x]]=G[map[y][x]][st]=min(G[st][map[y][x]], from.second+1);
            vis[y][x]=true;
            que.push(Pair(Point(x, y), from.second+1));
        }
    }
}

int main(void){
    int T;
    int from, to, dis;
    char tmp;
    
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &nx, &ny);
        size=0; n=1;
        for (int y=0; y<ny; y++){
            for (int x=0; x<nx; x++){
                do{scanf("%c", &tmp);
                }while (tmp=='\n');

                if (tmp=='A' || tmp=='S'){
                    points[n]=Point(x, y);
                    map[y][x]=n++;
                }else if (tmp=='#') map[y][x]=-1;
                else if (tmp==' ') map[y][x]=0;
            }
        }

        memset(G, INF, sizeof(G));
        for (int i=1; i<=n; i++){
            bfs(i);
            for (int j=i+1; j<=n; j++) if (G[i][j]!=INF)
                edges[size++]=Edge(i, j, G[i][j]);
        }printf("%d\n", Kruskal(n));
    }
    
    return 0;
}
