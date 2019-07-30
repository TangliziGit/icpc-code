#include <cstdio>
const int dir[8][2]={-2,-1, -2,1, -1,-2, -1,2, 1,-2, 1,2, 2,-1, 2,1};
struct Point{
    int x, y;
    Point(int x=0, int y=0):x(x),y(y) {}
};
int nx, ny;
bool dfs(int x, int y, int depth, Point path[], bool vis[][30]){
    if (depth==nx*ny) return true;
    
    for (int i=0; i<8; i++){
        int xx=x+dir[i][0], yy=y+dir[i][1];

        if (xx<0 || yy<0 || xx>=nx || yy>=ny) continue;
        if (vis[yy][xx]) continue;
        vis[yy][xx]=true; path[depth]=Point(xx, yy);
        if (dfs(xx, yy, depth+1, path, vis)) return true;
        vis[yy][xx]=false;
    }return false;
}

int main(void){
    int T;

    scanf("%d", &T);
    for (int kcase=0; kcase<T; kcase++){
        scanf("%d%d", &ny, &nx);

        Point path[30]={0}; bool vis[30][30]={0};
        vis[0][0]=true; path[0]=Point(0, 0);
        printf("Scenario #%d:\n", kcase+1);
        if (dfs(0, 0, 1, path, vis)) for (int i=0; i<nx*ny; i++)
            printf("%c%d", path[i].x+'A', path[i].y+1);
        else printf("impossible");
        printf("\n");
    }

    return 0;
}
