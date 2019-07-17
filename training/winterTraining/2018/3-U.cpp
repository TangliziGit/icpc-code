#include <cstdio>
#include <queue>
using namespace std;
int nx, ny, dir[4][2]={1, 0, 0, 1, -1, 0, 0, -1};
char map[25][25];
struct Point{
    int x, y;
    Point(int x=0, int y=0):
        x(x),y(y) {}
}points[400+5];
int bfs(int x, int y){
    queue<int> que; int size=1;
    points[0].x=x; points[0].y=y;
    que.push(0); map[y][x]='#';
    while (que.size()){
        int idx=que.front(); que.pop();
        for (int i=0; i<4; i++){
            int xx=points[idx].x+dir[i][0], yy=points[idx].y+dir[i][1];
            if (xx<0 || xx>=nx || yy<0 || yy>=ny) continue;
            if (map[yy][xx]=='#') continue;
            map[yy][xx]='#';
            points[size].x=xx; points[size].y=yy;
            que.push(size++);
        }
    }return size;
}

int main(void){
    while (scanf("%d%d", &nx, &ny)==2 && nx){
        for (int y=0; y<ny; y++) scanf("%s", map[y]);

        int ans;
        for (int y=0; y<ny; y++)
            for (int x=0; x<nx; x++)
                if (map[y][x]=='@') ans=bfs(x, y);
        printf("%d\n", ans);
    }

    return 0;
}
