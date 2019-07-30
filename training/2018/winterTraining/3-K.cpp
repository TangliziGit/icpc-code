#include <cstdio>
#include <queue>
using namespace std;
struct Point{
    int x, y;
    Point(int x=0, int y=0):x(x),y(y) {}
};
const int dir[8][2]={1,0, 1,-1, 0,-1, -1,-1, -1,0, -1,1, 0,1, 1,1};
char map[25][25];
int nx, ny;
int bfs(int sx, int sy){
    queue<Point> que; int perimeter=0;
    que.push(Point(sx, sy)); map[sy][sx]='#';
    while (que.size()){
        Point p=que.front(); que.pop();
        //perimeter+=edge(p);
        for (int i=0; i<8; i++){
            int xx=p.x+dir[i][0], yy=p.y+dir[i][1];

            if (yy<0 || xx<0 || yy>=ny || xx>=nx || map[yy][xx]=='.'){
                if (i%2==0) perimeter++;
                continue;
            }
            if (map[yy][xx]=='#') continue;
            map[yy][xx]='#';
            que.push(Point(xx, yy));
        }
    }return perimeter;
}

int main(void){
    int sx, sy;

    while (scanf("%d%d%d%d", &ny, &nx, &sy, &sx)==4 && nx){
        for (int y=0; y<ny; y++) scanf("%s", map[y]);
        printf("%d\n", bfs(sx-1, sy-1));
    }

    return 0;
}
