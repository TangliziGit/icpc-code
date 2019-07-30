#include <cstdio>
#include <cstring>
const int maxn=15+5;
const int dir[][2]={0,0, 0,1, 0,-1, 1,0, -1,0};
int nx, ny, ans_cnt;
int ans[maxn][maxn], map[maxn][maxn];
int tmp[maxn][maxn], tmap[maxn][maxn];

inline void flip(int x, int y){
    tmp[y][x]=1;
    for (int i=0; i<5; i++){
        int xx=x+dir[i][0], yy=y+dir[i][1];
        if (xx<0 || xx>=nx || yy<0 || yy>=ny)
            continue;
        tmap[yy][xx]=(tmap[yy][xx]+1)%2;
    }
}

bool check(void){
    for (int x=0; x<nx; x++) if (tmap[ny-1][x])
        return false;
    return true;
}

void show(void){
    for (int y=0; y<ny; y++, putchar('\n'))
        for (int x=0; x<nx; x++)
            printf("%d ", ans[y][x]);
}

void solve(void){
    ans_cnt=ny*nx+1;
    for (int line=0; line<(1<<nx); line++){
        int cnt=0;
        memset(tmp, 0, sizeof(tmp));
        memcpy(tmap, map, sizeof(map));
        for (int i=0; i<nx; i++)
            if (line & (1<<i)) flip(i, 0), cnt++;

        for (int y=1; y<ny; y++)
            for (int x=0; x<nx; x++) if (tmap[y-1][x]){
                flip(x, y); cnt++;
            }

        if (check() && cnt<ans_cnt){
            ans_cnt=cnt;
            memcpy(ans, tmp, sizeof(tmp));
        }
    }

    if (ans_cnt==ny*nx+1)
        printf("IMPOSSIBLE\n");
    else show();
}

int main(void){
    while (scanf("%d%d", &ny, &nx)==2){
        for (int y=0; y<ny; y++)
        for (int x=0; x<nx; x++)
            scanf("%d", &map[y][x]);
        solve();
    }

    return 0;
}
