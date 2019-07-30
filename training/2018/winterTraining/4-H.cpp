#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int dir[4][2]={1, 0, 0, 1, -1, 0, 0, -1};
int nx, ny, map[105][105], data[105][105];
int dp(int x, int y){
    // DAG dp
    if (data[y][x]!=-1) return data[y][x];
    data[y][x]=1;
    for (int i=0; i<4; i++){
        // for node in G[i]:
        int xx=x+dir[i][0], yy=y+dir[i][1];
        if (xx<0 || yy<0 || xx>=nx || yy>=ny) continue;
        if (map[yy][xx]>=map[y][x]) continue;
        data[y][x]=max(data[y][x], dp(xx, yy)+1);
    }return data[y][x];
}

int main(void){
    while (scanf("%d%d", &ny, &nx)==2){
        memset(data, -1, sizeof(data));
        for (int y=0; y<ny; y++)
            for (int x=0; x<nx; x++) scanf("%d", &map[y][x]);

        int max;
        for (int y=0; y<ny; y++)
            for (int x=0; x<nx; x++)
                if (max<dp(x, y) || y+x==0) max=dp(x, y);
        printf("%d\n", max);
    }

    return 0;
}
