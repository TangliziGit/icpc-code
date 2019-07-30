#include <cstdio>
int max(int a, int b){
    if (a>=b) return a;
    return b;
}

int main(void){
    int nflower, nvase, table[105][105], dp[105][105]={0};

    while (scanf("%d%d", &nflower, &nvase)==2){
        for (int fptr=1; fptr<=nflower; fptr++)
            for (int vptr=1; vptr<=nvase; vptr++)
                scanf("%d", &table[fptr][vptr]);
        
        dp[1][0]=table[1][1];
        for (int fi=1; fi<=nflower; fi++)
            for (int vi=fi; vi<=nvase; vi++)
                dp[fi][vi]=max(dp[fi-1][vi-1]+table[fi][vi], dp[fi][vi-1]);
        printf("%d\n", dp[nflower][nvase]);
    }
}
