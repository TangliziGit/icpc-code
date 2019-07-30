#include <cstdio>
#include <algorithm>
using namespace std;

int main(void){
    int n, weight, cost[int(4e3)], value[int(4e3)];

    while (scanf("%d%d", &n, &weight)==2){
        for (int i=0; i<n; i++) scanf("%d%d", &cost[i], &value[i]);

        int dp[int(2e4)]={0};
        for (int item=0; item<n; item++)
            for (int wei=weight; wei>0; wei--) if (wei>=cost[item])
                dp[wei]=max(dp[wei-cost[item]]+value[item], dp[wei]);
        printf("%d\n", dp[weight]);
    }

    return 0;
}
