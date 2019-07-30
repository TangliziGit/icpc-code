#include <cstdio>
#include <queue>
using namespace std;
const int n=8, dir[8][2]={-2,-1, -2,1, -1,-2, -1,2, 1,-2, 1,2, 2,-1, 2,1};
const char str[4][20]={"To get from ", " to ", " takes ", " knight moves."};
struct Point{
    int x, y, cnt;
    Point(int x=0, int y=0, int cnt=0):
        x(x),y(y),cnt(cnt) {}
};
int bfs(Point start, Point tar){
    queue<Point> que;
    bool vis[30][30]={0};
    vis[start.x][start.y]=true;
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
    char tarx, tary, startx, starty;
    while (scanf("%c%c%*c%c%c%*c", &startx, &starty, &tarx, &tary)==4){
        Point start(startx-'a', starty-'1'), tar(tarx-'a', tary-'1');
        printf("%s%c%c%s%c%c%s", str[0], startx, starty, str[1], tarx, tary, str[2]);
        if (tar.x==start.x && tar.y==start.y) printf("0%s\n", str[3]);
        else printf("%d%s\n", bfs(start, tar), str[3]);
    }

    return 0;
}
