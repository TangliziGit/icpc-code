#include <cstdio>
#include <algorithm>
int n, dp[100+5][100+5];

int main(void){
    while (scanf("%d", &n)==1 && n){
        for (int y=0; y<n; y++)
            for (int x=0; x<=y; x++) scanf("%d", &dp[y][x]);
        for (int y=n-2; y>=0; y--)
            for (int x=0; x<=y; x++)
                dp[y][x]+=std::max(dp[y+1][x], dp[y+1][x+1]);
        printf("%d\n", dp[0][0]);
    }

    return 0;
}
