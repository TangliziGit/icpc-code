#include <cstdio>
#include <queue>
using namespace std;
struct Point{
    int x, y, z, cnt;
    Point(int x=0, int y=0, int z=0, int cnt=0):
        x(x),y(y),z(z),cnt(cnt) {}
};
const int dir[6][3]={1,0,0, -1,0,0, 0,1,0, 0,-1,0, 0,0,1, 0,0,-1};
char map[15][15][15];
int n;
int bfs(Point start, Point tar){
    if (start.x==tar.x && start.y==tar.y && start.z==tar.z) return 0;
    queue<Point> que;
    que.push(start);
    map[start.z][start.y][start.x]='X';
    while (que.size()){
        Point p=que.front(); que.pop();

        for (int i=0; i<6; i++){
            int xx=p.x+dir[i][0], yy=p.y+dir[i][1], zz=p.z+dir[i][2];

            if (xx<0 || yy<0 || zz<0 || xx>=n || yy>=n || zz>=n) continue;
            if (map[zz][yy][xx]=='X') continue;
            if (xx==tar.x && yy==tar.y && zz==tar.z) return p.cnt+1;
            map[zz][yy][xx]='X';
            que.push(Point(xx, yy, zz, p.cnt+1));
        }
    }return -1;
}

int main(void){
    while (scanf("%*s%d", &n)==1){
        Point start, tar;
        for (int z=0; z<n; z++)
            for (int y=0; y<n; y++) scanf("%s", map[z][y]);
        scanf("%d%d%d%d%d%d%*s", &start.x, &start.y, &start.z,
            &tar.x, &tar.y, &tar.z);
        int ans=bfs(start, tar);
        if (ans>=0) printf("%d %d\n", n, ans);
        else printf("NO ROUTE\n");
    }

    return 0;
}
