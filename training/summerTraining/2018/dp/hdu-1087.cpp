#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(void){
    int n, chs[1000+5], dp[1000+5];

    while (scanf("%d", &n)==1 && n){
        memset(dp, 0, sizeof(dp));
        for (int i=1; i<=n; i++) scanf("%d", &chs[i]);

        dp[0]=chs[0]=0; chs[n+1]=0;
        for (int i=1; i<=n+1; i++){
            for (int j=i-1; j>=0; j--) if (chs[j]<chs[i] || i==n+1)
                dp[i]=max(dp[i], dp[j]);
            dp[i]+=chs[i];
        }
        printf("%d\n", dp[n+1]);
    }

    return 0;
}
