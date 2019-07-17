#include <cstdio>
#include <queue>
using namespace std;
const int dir[8][2]={-2,-1, -2,1, -1,-2, -1,2, 1,-2, 1,2, 2,-1, 2,1};
struct Point{
    int x, y, cnt;
    Point(int x=0, int y=0, int cnt=0):
        x(x),y(y),cnt(cnt) {}
};
int n;
int bfs(Point start, Point tar){
    if (start.x==tar.x && start.y==tar.y) return 0;
    queue<Point> que;
    bool vis[300+5][300+5]={0};
    vis[start.y][start.x]=true;
    que.push(start);
    while (que.size()){
        Point p=que.front(); que.pop();

        for (int i=0; i<8; i++){
            int xx=p.x+dir[i][0], yy=p.y+dir[i][1];
            if (xx<0 || yy<0 || xx>=n || yy>=n) continue;
            if (vis[yy][xx]) continue;
            if (tar.x==xx && tar.y==yy) return p.cnt+1;
            vis[yy][xx]=true;
            que.push(Point(xx, yy, p.cnt+1));
        }
    }return -1;
}

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        Point start, tar;
        scanf("%d%d%d%d%d", &n, &start.x, &start.y, &tar.x, &tar.y);
        printf("%d\n", bfs(start, tar));
    }

    return 0;
}

