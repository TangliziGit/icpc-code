#include <cstdio>
#include <algorithm>
using namespace std;
const int unit=1000;

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        int capital, years, n, cost[15], interest[15];
        scanf("%d%d%d", &capital, &years, &n);
        for (int i=0; i<n; i++){
            scanf("%d%d", &cost[i], &interest[i]);
            cost[i]/=unit;
        }

        int dp[int(1e6)+5];
        for (int y=0; y<years; y++){
            for (int i=0; i<=capital/unit; i++){
                dp[i]=((i==0)?0:dp[i-1]);
                for (int j=0; j<n; j++) if (i>=cost[j])
                    dp[i]=max(dp[i], dp[i-cost[j]]+interest[j]);
            }
            capital+=dp[capital/unit];
        }printf("%d\n", capital);
    }

    return 0;
}
