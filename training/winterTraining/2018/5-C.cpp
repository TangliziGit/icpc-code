#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
struct Point{
    int x, y;
    Point(int x, int y):x(x),y(y) {}
};
const int dir[4][2]={1, 0, 0, 1, -1, 0, 0, -1};
int n, map[55][55], dis[55][55];
long long dp[55][55];
void bfs(int x, int y){
    memset(dis, -1, sizeof(dis));
    memset(dp, -1, sizeof(dp)); dp[n-1][n-1]=1;
    queue<Point> que;
    que.push(Point(x, y)); dis[y][x]=map[y][x];
    while (que.size()){
        Point p=que.front(); que.pop();

        for (int i=0; i<4; i++){
            int xx=p.x+dir[i][0], yy=p.y+dir[i][1];

            if (xx<0 || yy<0 || xx>=n || yy>=n) continue;
            if (dis[yy][xx]>=0 && map[yy][xx]+dis[p.y][p.x]>=dis[yy][xx]) continue;
            dis[yy][xx]=map[yy][xx]+dis[p.y][p.x];
            que.push(Point(xx, yy));
        }
    }
}

long long dfs(int x, int y){
    if (dp[y][x]!=-1) return dp[y][x];

    dp[y][x]=0;
    for (int i=0; i<4; i++){
        int xx=x+dir[i][0], yy=y+dir[i][1];

        if (xx<0 || yy<0 || xx>=n || yy>=n) continue;
        if (dis[yy][xx]>=dis[y][x]) continue;
        dp[y][x]+=dfs(xx, yy);
    }return dp[y][x];
}

int main(void){
    while (scanf("%d", &n)==1){
        for (int y=0; y<n; y++)
            for (int x=0; x<n; x++) scanf("%d", &map[y][x]);
        bfs(n-1, n-1);
        printf("%lld\n", dfs(0, 0));
        /*for (int i=0; i<n; i++, printf("\n"))
            for (int j=0; j<n; j++) printf("%d ", dp[i][j]);
        for (int i=0; i<n; i++, printf("\n"))
            for (int j=0; j<n; j++) printf("%d ", dis[i][j]);*/
    }
    return 0;
}
