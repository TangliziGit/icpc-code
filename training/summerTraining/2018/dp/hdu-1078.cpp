#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100+5, Dir[4][2]={-1,0, 0,-1, 1,0, 0,1};
int n, m;
int map[maxn][maxn], data[maxn][maxn];
bool vis[maxn][maxn];
int dp(int x, int y){
    if (vis[y][x]) return data[y][x];

    for (int dir=0; dir<4; dir++)
        for (int k=1; k<=m; k++){
            int xx=x+Dir[dir][0]*k, yy=y+Dir[dir][1]*k;

            if (xx<0 || yy<0 || xx>=n || yy>=n) continue;
            if (map[yy][xx]<=map[y][x]) continue;
            data[y][x]=max(data[y][x], dp(xx, yy));
        }
    vis[y][x]=true;
    return data[y][x]+=map[y][x];
}

int main(void){
    while (scanf("%d%d", &n, &m)==2 && n>0){
        memset(vis, false, sizeof(vis));
        memset(data, 0, sizeof(data));
        for (int y=0; y<n; y++)
            for (int x=0; x<n; x++) scanf("%d", &map[y][x]);
        printf("%d\n", dp(0, 0));
    }

    return 0;
}
