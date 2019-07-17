#include <cstdio>
int nx, ny;
char map[55][55];
int dir[4][2]={{1,0}, {0,1}, {-1,0}, {0,-1}};
bool check(int y, int x){
    for (int i=0; i<4; i++){
        int yy=y+dir[i][1], xx=x+dir[i][0];
        if (yy<0 || xx<0 || xx>=nx || yy>=ny) continue;
        if (map[yy][xx]=='#') return true;
    }return false;
}

int main(void){
    char tmp;

    scanf("%d%d", &nx, &ny);
    for (int y=0; y<ny; y++) scanf("%s", map[y]);

    bool flg=true;
    for (int y=0; y<ny; y++){
        for (int x=0; x<nx; x++)
            if (map[y][x]=='#' && check(y, x)==false) {
                flg=false;
                break;
            }
        if (flg==false) break;
    }

    if (flg) printf("Yes\n");
    else printf("No\n");

    return 0;
}
