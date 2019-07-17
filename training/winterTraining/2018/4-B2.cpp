// haha, there must be something wrong in my brain
#include <cstdio>

int main(void){
    int f, v, map[105][105], dp[105][105];

    while (scanf("%d%d", &f, &v)==2){
        for (int i=0; i<f; i++)
            for (int j=0; j<v; j++){
                scanf("%d", &map[i][j]);
                dp[i][j]=((i==f-1)?0:-55);
            }

        for (int i=f-1; i>0; i--)
            for (int j=i; j<i+f; j++){
                int ptr=j-1, tmp=map[i][j]+dp[i][j]; 
                while (ptr>=i-1 && tmp>dp[i-1][ptr]){
                    dp[i-1][ptr]=tmp; ptr--;
                }
            }

        int max=0;
        for (int i=0; i<f; i++)
            if (max<map[0][i]+dp[0][i] || i==0) max=map[0][i]+dp[0][i];
        printf("%d\n", max);
    }

    return 0;
}
