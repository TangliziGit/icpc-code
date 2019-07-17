#include <cstdio>
const int space=0, block=1, start=2, goal=3,
    dir[4][2]={1,0,0,1,-1,0,0,-1};
int mx, my, ex, ey;
inline bool check(int x, int y){
    if (x<0 || x>=mx || y<0 || y>=my) return true;
    return false;
}

int dfs(int dpth, int &maxd, int x, int y, int map[][25]){
    if (map[y][x]==goal) return 1;
    if (dpth==maxd) return 0;

    for (int i=0; i<4; i++){
        int xx=x+dir[i][0], yy=y+dir[i][1];
        if (check(xx, yy)) continue;
        if (map[yy][xx]==block) continue;

        while (!check(xx, yy) && (map[yy][xx]==space || map[yy][xx]==start)){
            xx+=dir[i][0]; yy+=dir[i][1];
        }
        if (check(xx, yy)) continue;
        if (map[yy][xx]==goal) return 1;
        else if (map[yy][xx]==block){
            map[yy][xx]=space;
            if (dfs(dpth+1, maxd, xx-dir[i][0], yy-dir[i][1], map)) return 1;
            map[yy][xx]=block;
        }
    }return 0;
}

int main(void){
    int map[25][25], sx, sy;
    while (scanf("%d%d", &mx, &my)==2 && mx){
        for (int y=0; y<my; y++)
            for (int x=0; x<mx; x++){
                scanf("%d", &map[y][x]);
                if (map[y][x]==start) {sx=x; sy=y;}
                else if (map[y][x]==goal) {ex=x; ey=y;}
            }
        
        int isdone=0;
        for (int maxd=1; maxd<=10; maxd++)
            if (dfs(0, maxd, sx, sy, map)){
                printf("%d\n", maxd); isdone=1;
                break;
            }
        if (isdone==0) printf("-1\n");
    }
    
    return 0;
}