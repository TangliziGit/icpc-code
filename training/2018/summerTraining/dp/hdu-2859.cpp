#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+5;
int n, data[maxn][maxn];
char map[maxn][maxn];
int dp(int x, int y){
    if (y==0 || x==n-1) return 1;
    if (data[y][x]) return data[y][x];
    int cnt=0;
    while (x+cnt<n && y-cnt>=0 && (map[x+cnt][y]==map[x][y-cnt])) cnt++;
    return data[y][x]=min(cnt, dp(x+1, y-1)+1);
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        memset(data, 0, sizeof(data));
        for (int y=0; y<n; y++) scanf("%s", map[y]);

        int ans=0;
        for (int y=0; y<n; y++)
            for (int x=0; x<n; x++)
                ans=max(ans, dp(x, y));
        printf("%d\n", ans);
    }

    return 0;
}
