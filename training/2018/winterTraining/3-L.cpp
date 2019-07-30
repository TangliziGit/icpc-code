#include <cstdio>
char map[100+5][100+5];
int nx, ny, dir[8][2]={-1, -1, 0, -1, 1, -1,-1, 0, 1, 0, -1, 1, 0, 1, 1, 1};
void dfs(int x, int y){
    map[y][x]='*';
    for (int i=0; i<8; i++){
        int xx=x+dir[i][0], yy=y+dir[i][1];

        if (xx<0 || yy<0 || xx>=nx || yy>=ny) continue;
        if (map[yy][xx]=='*') continue;
        dfs(xx, yy);
    }
}

int main(void){
    while (scanf("%d%d", &ny, &nx)==2 && ny){
        for (int y=0; y<ny; y++) scanf("%s", map[y]);

        int cnt=0;
        for (int y=0; y<ny; y++)
            for (int x=0; x<nx; x++)
                if (map[y][x]=='@') {dfs(x, y); cnt++;}
        printf("%d\n", cnt);
    }

    return 0;
}
